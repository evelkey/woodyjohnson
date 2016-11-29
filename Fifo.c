#include "Fifo.h"

void FifoInit(pFifo_t pfifo,uint8_t* pdata,uint8_t length){
	int i=0;
	if (length==0){
		pfifo->data=0;
		pfifo->size=0;
		pfifo->wptr=0;
		pfifo->rptr=0;
		pfifo->datalen=sizeof(uint8_t);
	}
	else{
		pfifo->data=pdata;
		pfifo->size=length;
		pfifo->wptr=0;
		pfifo->rptr=0;
		pfifo->datalen=sizeof(uint8_t);


	}

}



uint8_t FifoPop(pFifo_t pfifo,uint8_t* pdata)
{
	if(pfifo->rptr == pfifo->wptr) //ha üres
	{
		return 0;
	}

	*pdata = pfifo->data[pfifo->rptr];

	pfifo->rptr++;

	if(pfifo->size == pfifo->rptr)
	{
		pfifo->rptr = 0;
	}

	return 1;
}




uint8_t FifoPush(pFifo_t pfifo,uint8_t data){
	if((pfifo->wptr==pfifo->size-1 && pfifo->rptr==0) || pfifo->wptr==pfifo->rptr-1){
		return 0;
	}

	pfifo->data[pfifo->wptr]=data;

	if(pfifo->wptr==pfifo->size-1){
		pfifo->wptr=0;
	}
	else{
		pfifo->wptr++;
	}

	return 1;

}
