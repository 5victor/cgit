#ifndef CGIT_H
#define CGIT_H

#include "git.h"
#include <openssl/sha.h>
#include <ctype.h>
#include <sched.h>

typedef void (*configfn)(const char *name, const char *value);

struct cacheitem {
	char *name;
	struct stat st;
	int ttl;
	int fd;
};

extern char *cgit_root;
extern char *cgit_root_title;
extern char *cgit_css;
extern char *cgit_logo;
extern char *cgit_logo_link;
extern char *cgit_virtual_root;
extern char *cgit_cache_root;

extern int cgit_cache_root_ttl;
extern int cgit_cache_repo_ttl;
extern int cgit_cache_dynamic_ttl;
extern int cgit_cache_static_ttl;
extern int cgit_cache_max_create_time;

extern char *cgit_repo_name;
extern char *cgit_repo_desc;
extern char *cgit_repo_owner;

extern int cgit_query_has_symref;
extern int cgit_query_has_sha1;

extern char *cgit_querystring;
extern char *cgit_query_repo;
extern char *cgit_query_page;
extern char *cgit_query_head;
extern char *cgit_query_sha1;

extern int htmlfd;

extern char *fmt(const char *format,...);

extern void html(const char *txt);
extern void htmlf(const char *format,...);
extern void html_txt(char *txt);
extern void html_attr(char *txt);
extern void html_link_open(char *url, char *title, char *class);
extern void html_link_close(void);


extern int cgit_read_config(const char *filename, configfn fn);

extern void cache_prepare(struct cacheitem *item);
extern int cache_lock(struct cacheitem *item);
extern int cache_unlock(struct cacheitem *item);
extern int cache_exist(struct cacheitem *item);
extern int cache_expired(struct cacheitem *item);

#endif /* CGIT_H */
