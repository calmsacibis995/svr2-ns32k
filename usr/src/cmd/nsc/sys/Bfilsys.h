#define BICFREE	178
#define BICINOD	100
/*
 * @(#)filsys.h	3.3	7/14/83
 * @(#)Copyright (C) 1983 by National Semiconductor Corp.
 */

/*
 * Structure of the super-block
 */
struct	Bfilsys
{
	unsigned short s_isize;		/* size in blocks of i-list */
	daddr_t	s_fsize;   		/* size in blocks of entire volume */
	short  	s_nfree;   		/* number of addresses in s_free */
	daddr_t	s_free[BICFREE];	/* free block list */
	short  	s_ninode;  		/* number of i-nodes in s_inode */
	ino_t  	s_inode[BICINOD];	/* free i-node list */
	char   	s_flock;   		/* lock during free list manipulation */
	char   	s_ilock;   		/* lock during i-list manipulation */
	char   	s_fmod;    		/* super block modified flag */
	char   	s_ronly;   		/* mounted read-only flag */
	time_t 	s_time;    		/* last super block update */
	daddr_t	s_tfree;   		/* total free blocks*/
	ino_t  	s_tinode;  		/* total free inodes */
	/* begin not maintained by this version of the system */
	short	s_dinfo[2];		/* interleave stuff */
#define	s_m	s_dinfo[0]
#define	s_n	s_dinfo[1]
	/* end not maintained */
	char   	s_fname[12];		/* file system name */
	ino_t	s_lasti;		/* start place for circular search */
	ino_t	s_nbehind;		/* est # free inodes before s_lasti */
};

#ifdef KERNEL
struct	filsys *getfs();
#endif
