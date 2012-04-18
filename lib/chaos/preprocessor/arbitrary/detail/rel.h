# /* ********************************************************************
#  *                                                                    *
#  *    (C) Copyright Paul Mensonides 2003-2005.                        *
#  *                                                                    *
#  *    Distributed under the Boost Software License, Version 1.0.      *
#  *    (See accompanying file LICENSE).                                *
#  *                                                                    *
#  *    See http://chaos-pp.sourceforge.net for most recent version.    *
#  *                                                                    *
#  ******************************************************************** */
#
# ifndef CHAOS_PREPROCESSOR_ARBITRARY_DETAIL_REL_H
# define CHAOS_PREPROCESSOR_ARBITRARY_DETAIL_REL_H
#
# include <chaos/preprocessor/arbitrary/detail/lookup.h>
#
# /* CHAOS_PP_ARBITRARY_REL */
#
# define CHAOS_PP_ARBITRARY_REL(a, b) \
    CHAOS_PP_ARBITRARY_LOOKUP(a, CHAOS_PP_ARBITRARY_LOOKUP(b, ( \
        (1, 2, 2, 2, 2, 2, 2, 2, 2, 2), \
        (0, 1, 2, 2, 2, 2, 2, 2, 2, 2), \
        (0, 0, 1, 2, 2, 2, 2, 2, 2, 2), \
        (0, 0, 0, 1, 2, 2, 2, 2, 2, 2), \
        (0, 0, 0, 0, 1, 2, 2, 2, 2, 2), \
        (0, 0, 0, 0, 0, 1, 2, 2, 2, 2), \
        (0, 0, 0, 0, 0, 0, 1, 2, 2, 2), \
        (0, 0, 0, 0, 0, 0, 0, 1, 2, 2), \
        (0, 0, 0, 0, 0, 0, 0, 0, 1, 2), \
        (0, 0, 0, 0, 0, 0, 0, 0, 0, 1) \
    ))) \
    /**/
#
# endif
