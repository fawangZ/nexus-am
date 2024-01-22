#include <klib.h>

#if 1
#define CACHE_CTL_BASE 	0x39000000
#define CACHE_CTL_TAGR   0x100 
#define CACHE_CTL_SETR   0x108
#define CACHE_CTL_CMDR   0x200
#define SRAM_BASE0 0x1001000000
#define SRAM_BASE1 0x1001100000
#define SRAM_BASE2 0x1001200000
#define SRAM_BASE3 0x1001300000
#define SRAM_BASE4 0x1001400000

#define DDR_BASE_TEST 0x1010000000
//#define DDR_BASE_TEST 0x90000000

#define MEM_WRITEW(addr, val) 	((*((volatile unsigned long long *)((unsigned long long)addr))) = (val))
#define MEM_READW(addr)		(*((volatile unsigned long long *)((unsigned long long)addr)))	 
#endif

int main()
{
	__asm__ volatile("nop");
	unsigned int num = 0;

#if 1
	MEM_WRITEW(SRAM_BASE0 , 9);
	num = MEM_READW(SRAM_BASE0);
	__asm__ volatile("fence");
	MEM_WRITEW(SRAM_BASE1 , 10);
	MEM_WRITEW(SRAM_BASE2 , 11);
	MEM_WRITEW(SRAM_BASE3 , 12);
	MEM_WRITEW(SRAM_BASE4 , 13);
	/* set tag */
	MEM_WRITEW(CACHE_CTL_BASE + CACHE_CTL_TAGR, 0x20020);
	MEM_WRITEW(CACHE_CTL_BASE + CACHE_CTL_SETR, 0);
	MEM_WRITEW(CACHE_CTL_BASE + CACHE_CTL_CMDR, 18);
#else
	MEM_WRITEW(DDR_BASE_TEST, 9);
	__asm__ volatile("fence");	
	num = MEM_READW(DDR_BASE_TEST);
	/* set tag */
	//MEM_WRITEW(CACHE_CTL_BASE + CACHE_CTL_TAGR, 0x1200);
	MEM_WRITEW(CACHE_CTL_BASE + CACHE_CTL_TAGR, 0x20000);
	MEM_WRITEW(CACHE_CTL_BASE + CACHE_CTL_SETR, 0);
	MEM_WRITEW(CACHE_CTL_BASE + CACHE_CTL_CMDR, 18);
#endif
	__asm__ volatile("nop");
	__asm__ volatile("nop");
    printf("Hello, XiangShan! num:%d \n", num);
    printf("Hello, XiangShan!\n");
    return 0;
}
