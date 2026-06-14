/*
 * CDDL HEADER START
 *
 * The contents of this file are subject to the terms of the
 * Common Development and Distribution License (the "License").
 * You may not use this file except in compliance with the License.
 *
 * You can obtain a copy of the license at usr/src/OPENSOLARIS.LICENSE
 * or http://www.opensolaris.org/os/licensing.
 * See the License for the specific language governing permissions
 * and limitations under the License.
 *
 * When distributing Covered Code, include this CDDL HEADER in each
 * file and include the License file at usr/src/OPENSOLARIS.LICENSE.
 * If applicable, add the following below this CDDL HEADER, with the
 * fields enclosed by brackets "[]" replaced with your own identifying
 * information: Portions Copyright [yyyy] [name of copyright owner]
 *
 * CDDL HEADER END
 */
#ifdef COMPAT_SOLARIS
#include <sys/param.h>
#include <sys/types.h>
#include <sys/sysmacros.h>
#include <sys/inline.h>
#include <sys/varargs.h>
#include <sys/systm.h>
#include <sys/conf.h>
#include <sys/cmn_err.h>
#include <sys/syslog.h>
#include <sys/log.h>
#include <sys/proc.h>
#include <sys/vnode.h>
#include <sys/session.h>
#include <sys/stream.h>
#include <sys/kmem.h>
#include <sys/kobj.h>
#include <sys/atomic.h>
#include <sys/console.h>
#include <sys/cpuvar.h>
#include <sys/modctl.h>
#include <sys/reboot.h>
#include <sys/debug.h>
#include <sys/panic.h>
#include <sys/spl.h>
#include <sys/zone.h>
#include <sys/sunddi.h>

void
dev_err(dev_info_t *dip, int ce, char *fmt, ...)
{
	va_list adx;

	va_start(adx, fmt);
	vcmn_err(ce, fmt, adx);
	va_end(adx);
}
#endif /* COMPAT_SOLARIS */
