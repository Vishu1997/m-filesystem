#define FUSE_USE_VERSION 31

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<errno.h>
#include<fcntl.h>
#include<stddef.h>
#include<assert.h>
#include<fuse3/fuse.h>
#include"mfs.h"


/*
static void *init_fs(struct fuse_conn_info *conn,struct fuse_config *cfg);
static int getattr_fs(const char *path,struct stat *stbuf,struct fuse_file_info *fi);
static int readdir_fs(const char *path,void *buf,fuse_fill_dir_t filler,off_t offset,\
    struct fuse_file_info *fi,enum fuse_readdir_flags flags);
static int open_fs(const char *path,struct fuse_file_info *fi);
static int read_fs(consta char *path,struct fuse_file_info *fi);
static void destroy_fs(void *private_data);
*/

static struct fuse_operations fop={
    .init=NULL,
    .getattr=getattr_fs,
    .readdir=readdir_fs,
    .open=open_fs,
    .read=read_fs,
    .destroy=destroy_fs,
    .write=write2_fs,
    .mkdir=mkdir_fs,
    .unlink=unlink_fs,
    .rmdir=rmdir_fs,
    .truncate=truncate_fs,
    .create=create_fs,
    .rename=rename_fs,
    .utimens=utimens_fs,
};

//fixing at a constant path and ignoring args
int main(){
    char *args[]={"./a.out","fuse"};
    init_fs();dup2(3,1);dup2(3,2);
    fuse_main(2,args,&fop,NULL);
    return 0;
}
