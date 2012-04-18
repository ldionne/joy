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
# ifndef CHAOS_PREPROCESSOR_LOGICAL_NOR_H
# define CHAOS_PREPROCESSOR_LOGICAL_NOR_H
#
# include <chaos/preprocessor/cat.h>
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/lambda/ops.h>
# include <chaos/preprocessor/logical/bool.h>
# include <chaos/preprocessor/logical/not.h>
#
# /* CHAOS_PP_NOR */
#
# define CHAOS_PP_NOR(p) CHAOS_PP_CAT(CHAOS_IP_NOR_, CHAOS_PP_BOOL(p))
# define CHAOS_PP_NOR_ID() CHAOS_PP_NOR
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_NOR_ CHAOS_PP_LAMBDA(CHAOS_PP_NOR)
# endif
#
# define CHAOS_IP_NOR_0(q) CHAOS_PP_NOT(q)
# define CHAOS_IP_NOR_1(q) 0
#
# endif
