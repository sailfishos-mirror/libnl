/* SPDX-License-Identifier: LGPL-2.1-only */
/*
 * Copyright (c) 2010 Thomas Graf <tgraf@suug.ch>
 */

#ifndef NETLINK_LINK_INET_H_
#define NETLINK_LINK_INET_H_

#include <netlink/netlink.h>
#include <netlink/route/link.h>

#ifdef __cplusplus
extern "C" {
#endif

extern const char *	rtnl_link_inet_devconf2str(int, char *, size_t);
extern int		rtnl_link_inet_str2devconf(const char *);

extern int		rtnl_link_inet_get_conf(struct rtnl_link *,
						const unsigned int, uint32_t *);
extern int		rtnl_link_inet_set_conf(struct rtnl_link *,
						const unsigned int, uint32_t);

#ifdef __cplusplus
}
#endif

#endif
