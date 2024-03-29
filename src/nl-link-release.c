/* SPDX-License-Identifier: LGPL-2.1-only */
/*
 * Copyright (c) 2011 Thomas Graf <tgraf@suug.ch>
 */

#include "nl-default.h"

#include <linux/netlink.h>

#include <netlink/cli/utils.h>
#include <netlink/cli/link.h>
#include <netlink/route/link/bonding.h>

int main(int argc, char *argv[])
{
	struct nl_sock *sock;
	struct nl_cache *link_cache;
	struct rtnl_link *slave;
	int err;

	if (argc < 2) {
		fprintf(stderr, "Usage: nl-link-release slave\n");
		return 1;
	}

	sock = nl_cli_alloc_socket();
	nl_cli_connect(sock, NETLINK_ROUTE);
	link_cache = nl_cli_link_alloc_cache(sock);

	if (!(slave = rtnl_link_get_by_name(link_cache, argv[1]))) {
		fprintf(stderr, "Unknown link: %s\n", argv[1]);
		return 1;
	}

	if ((err = rtnl_link_bond_release(sock, slave)) < 0) {
		fprintf(stderr, "Unable to release slave %s: %s\n",
			argv[1], nl_geterror(err));
		return 1;
	}

	return 0;
}

