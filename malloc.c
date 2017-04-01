
//
//  main.c
//  可变分区存储管理
//  Created by Halley on 17/4/1.
//  Copyright © 2017年 Halley. All rights reserved.
//
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/malloc.h>

/* 表的定义 */
#define N 5
struct map {  /* 空闲存储区表 */
    unsigned	m_size;
    char		*m_addr;
};
struct map coremap[N];

/* 首次适应的分配函数 */
char *fmalloc( unsigned size )
/* 由于本函数只管理内存空间的分配，不需要核心代码的mp参数）*/
{
    register char		*a;
    register struct map	*bp;
    for ( bp = coremap; bp->m_size; bp++ )                  /* 从表首开始搜索 */
    {
        if ( bp->m_size >= size )                           /* 找到够用的空闲区 */
        {
            a		= bp->m_addr;
            bp->m_addr	+= size;                            /* 修改空闲项起始地址 */
            if ( (bp->m_size -= size) == 0 )                /* 修改大小 */
                do                                          /* 该项空闲区全部被分配，删去该项 */
                {
                    bp++;
                    (bp - 1)->m_addr = bp->m_addr;
                }
            while ( ((bp - 1)->m_size = bp->m_size) );
            return(a);                                      /* 返回分配到的空闲区始址 */
        }
    }
    return(0);                                              /* 无足够大小的空闲区 */
}


/* 首次适应的释放函数 */
void ffree( unsigned size, char *aa )
{
    struct map	*bp;
    char		*a, *t;
    unsigned	tt;
    a = aa;
    for ( bp = coremap; bp->m_addr <= a && bp->m_size != 0; bp++ )
        ;
    if ( bp > coremap && (bp - 1)->m_addr + (bp - 1)->m_size == a ) /* 情况1和2 */
    {
        (bp - 1)->m_size += size;                                   /* 情况1，与上空闲区合并 */
        if ( a + size == bp->m_addr )                               /* 情况2，又与下空闲区合并 */
        {
            (bp - 1)->m_size += bp->m_size;
            while ( bp->m_size )                                    /* 删除下空闲区 */
            {
                bp++;
                (bp - 1)->m_addr	= bp->m_addr;
                (bp - 1)->m_size	= bp->m_size;
            }
        }
    }else  {
        if ( a + size == bp->m_addr && bp->m_size )                 /* 情况3，仅与下空闲区合并 */
        {
            bp->m_addr	-= size;
            bp->m_size	+= size;
        }else                                                       /* 情况4，插入一个新空闲区 */
            if ( size )
                do
                {
                    t		= bp->m_addr;
                    bp->m_addr	= a;
                    a		= t;
                    tt		= bp->m_size;
                    bp->m_size	= size;
                    bp++;
                }
        while ( (size = tt) );
    }
}


/*  coremap表的初始化程序 */
void initCoremap( base_addr, size )
char *base_addr;
unsigned size;
{
    /* 第一项的m_addr指向用malloc申请到的addr，
     * 第一项的m_size等于malloc申请的size，
     * 其他各项清0 */
    
    int i;
    coremap[0].m_addr	= base_addr;
    coremap[0].m_size	= size;
    for ( i = 1; i < N; i++ )
    {
        coremap[i].m_size	= 0;
        coremap[i].m_addr	= 0;
    }
}

void printCoremap( base_addr )  /* 输出表的内容 */
char *base_addr;
{
    int i, zero = 0;
    printf( "	    Size\tR_Addr \t\tAddr\n");
    for ( i = 0; i < N; i++ )
    {
        if ( coremap[i].m_size != 0 )
            printf( "coremap[%d]: %u\t\t%u\t\t%u\n", i, coremap[i].m_size,
                   coremap[i].m_addr - base_addr, coremap[i].m_addr );
        else
            printf( "coremap[%d]: %u\t\t%u\t\t%u\n", i, coremap[i].m_size, zero, zero );
    }
}

void shouHelp()  /* 显示帮助信息 */
{
    printf( "m size : 分配内存\n" );
    printf( "f size addr : 释放内存\n" );
    printf( "p : 打印coremap表\n" );
    printf( "h : 显示帮助信息\n" );
    printf( "q : 退出执行\n" );
}


void main()
{
    unsigned	size, total_size;
    char		*base_addr, *addr, *start_addr, cmdchar;
    unsigned	r_addr;
    printf( "Please Input malloc size: " );
    scanf( "%u", &total_size );
    base_addr = malloc( total_size );
    initCoremap( base_addr, total_size );
    do
    {
        printf( "Please Input command, h for help.\n" );
        do                                                                  /* 过滤空白字符 */
            cmdchar = getchar();
        while ( cmdchar == ' ' || cmdchar == '\t' || cmdchar == '\n' );
        switch ( cmdchar )
        {
            case 'm':                                                       /* 分配内存空间 */
                scanf( "%u", &size );
                if ( size < 0 || size >= total_size )
                {
                    printf( "参数size错误\n{size}" );
                    break;
                }
                start_addr = fmalloc( size );
                if ( start_addr == 0 )
                    printf( "没有足够大的空闲分区\n" );
                break;
            case 'f':                                                       /* 释放分配的内存空间 */
                scanf( "%u%u", &size, &r_addr );
                if ( r_addr < 0 || r_addr >= total_size )
                {
                    printf( "释放空闲区的起始地址超出范围\n" );
                    break;
                }
                addr = base_addr + r_addr;
                ffree( size, addr );
                break;
            case 'p':                                                       /* 输出coremap表 */
                printCoremap( base_addr );
                break;
            case 'h':                                                       /* 输出帮助信息 */
                shouHelp();
                break;
            case 'q':                                                       /* 退出执行 */
                break;
            default:
                printf( "非法命令，显示帮助信息，请键入“h”\n" );
                continue;
        }
    }
    while ( cmdchar != 'q' );
    free( base_addr );                                                      /* 释放用malloc申请到的内存 */
    return;
}
