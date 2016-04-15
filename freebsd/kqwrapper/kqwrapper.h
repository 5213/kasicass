#ifndef SGE_KQUEUE_WRAPPER
#define SGE_KQUEUE_WRAPPER

// simple kqueue wrapper for server-side program
// 1. ��������ֻ��������һ�� kqueue
//
// Author: Kasicass
// Date  : 2008-12-11


//
// Constants
//

#define	KQW_BACKLOG		128			// backlog for listen fd

#define	MAX_KQ_EVENTS		(1024 * 2)		// 2000+ ��������ÿ�η���ô? ����Ц
#define	MAX_EVENTS		(1024 * 20)		// 1024 * 20 * sizeof(struct _kqw_event) == 0.48 Mb
							// ��� fd й¶, ����ϵͳ�����, �Լ����� crash Ҳ������ν��

#define	KQW_TIMERFD_1		(MAX_EVENTS-1)		// little trick, ʹ����󼸸� slot
#define	KQW_TIMERFD_2		(MAX_EVENTS-2)		// timer event �͸� 5 ������
#define	KQW_TIMERFD_3		(MAX_EVENTS-3)
#define	KQW_TIMERFD_4		(MAX_EVENTS-4)
#define	KQW_TIMERFD_5		(MAX_EVENTS-5)



//
// TCP Socket Stuff
//

// backlog ��Ϊ����, ������ĺ궨�弴��
// fd - �ɹ�
// -1 - ʧ��
int kqw_create_listen_socket(int port);




// 
// Event Stuff
//

typedef void (*kqw_ev_handler) (int fd, void *data);

// ��ʼ�� kqueue
// -1 - ʧ��
// 0  - �ɹ�
int kqw_init();

// listen event
int kqw_add_listen_event(int fd, kqw_ev_handler listen_cb, void *data);

// ��� read/write event
// write event is ONESHOT
int kqw_add_read_event(int fd, kqw_ev_handler read_cb, void *data);
int kqw_add_write_event(int fd, kqw_ev_handler write_cb, void *data);

// ��� timer event
int kqw_add_timer(int fd, int interval, kqw_ev_handler timer_cb, void *data);

// ���� del listen/client_conn/timer �κ����͵� fd
// ��Ϊ write event �� ONESHOT ��, �����ʵ����ֻ���� listen/read/timer event
int kqw_del_event(int fd);

// ÿ�����¼�����, ��ص���Ӧ�� handler, ͬʱ����
//
// ��׼ main loop
// while (1) {
//   pre do ...
//   if ( kqw_event_dispatch() == KQW_DISPATCH_FATAL )
//   {
//     ba .. ba la ...
//   }
//   post do...
// }
//
// -1 - FATAL ERROR
// 0  - �ɹ�
int kqw_event_dispatch();

#endif /* SGE_KQUEUE_WRAPPER */

