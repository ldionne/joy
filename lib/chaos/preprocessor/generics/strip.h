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
# ifndef CHAOS_PREPROCESSOR_GENERICS_STRIP_H
# define CHAOS_PREPROCESSOR_GENERICS_STRIP_H
#
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/lambda/ops.h>
# include <chaos/preprocessor/tuple/eat.h>
#
# /* CHAOS_PP_STRIP */
#
# define CHAOS_PP_STRIP(g) CHAOS_PP_EAT g
# define CHAOS_PP_STRIP_ID() CHAOS_PP_STRIP
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_STRIP_ CHAOS_PP_LAMBDA(CHAOS_PP_STRIP_ID)()
# endif
#
# endif
