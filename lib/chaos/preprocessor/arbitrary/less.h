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
# ifndef CHAOS_PREPROCESSOR_ARBITRARY_LESS_H
# define CHAOS_PREPROCESSOR_ARBITRARY_LESS_H
#
# include <chaos/preprocessor/arbitrary/less_equal.h>
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/lambda/ops.h>
# include <chaos/preprocessor/logical/compl.h>
#
# /* CHAOS_PP_ARBITRARY_LESS */
#
# define CHAOS_PP_ARBITRARY_LESS(x, y) CHAOS_PP_COMPL(CHAOS_PP_ARBITRARY_LESS_EQUAL(y, x))
# define CHAOS_PP_ARBITRARY_LESS_ID() CHAOS_PP_ARBITRARY_LESS
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_ARBITRARY_LESS_ CHAOS_PP_LAMBDA(CHAOS_PP_ARBITRARY_LESS)
# endif
#
# /* CHAOS_PP_ARBITRARY_LESS_INTERNAL */
#
# define CHAOS_PP_ARBITRARY_LESS_INTERNAL(x, y) CHAOS_PP_COMPL(CHAOS_PP_ARBITRARY_LESS_EQUAL_INTERNAL(y, x))
#
# endif
