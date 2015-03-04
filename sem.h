/*
 * =====================================================================================
 *
 *       Filename:  locker.h
 *
 *    Description:  线程同步机制封装
 *
 *        Version:  1.0
 *        Created:  09/02/15 02:25:26
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Jeff (), zyfforlinux@163.com
 *   Organization:  Linux
 *
 * =====================================================================================
 */

#ifdef LOCKER_H_
#define LOCKER_H_

#include <pthread.h>
#include <semaphore.h>

//封装信号量
class sem
{
public:
	sem()
	{
		if(sem_init(&m_sem,0,0) != 0)
		{
			throw std:exception();
		}
	}
	
	~sem()
	{
		sem_destroy(&m_sem);
	}
	
	bool wait()
	{
		return sem_wait(&m_sem) == 0;
	}

	bool post()
	{
		return sem_post(&m_sem) == 0;
	}
private:
	sem_t m_sem;
};

#endif //end sem.h
