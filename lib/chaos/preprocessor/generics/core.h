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
# ifndef CHAOS_PREPROCESSOR_GENERICS_CORE_H
# define CHAOS_PREPROCESSOR_GENERICS_CORE_H
#
# include <chaos/preprocessor/cat.h>
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/generics/strip.h>
# include <chaos/preprocessor/generics/typeof.h>
# include <chaos/preprocessor/lambda/ops.h>
# include <chaos/preprocessor/tuple/eat.h>
# include <chaos/preprocessor/tuple/rem.h>
#
# /* CHAOS_PP_TAG */
#
# define CHAOS_PP_TAG(type) CHAOS_PP_PRIMITIVE_CAT(type, _TAG)
# define CHAOS_PP_TAG_ID() CHAOS_PP_TAG
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_TAG_ CHAOS_PP_LAMBDA(CHAOS_PP_TAG)
# endif
#
# /* CHAOS_PP_NIL */
#
# define CHAOS_PP_NIL(type) (type) CHAOS_PP_PRIMITIVE_CAT(type, _NIL)()
# define CHAOS_PP_NIL_ID() CHAOS_PP_NIL
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_NIL_ CHAOS_PP_LAMBDA(CHAOS_PP_NIL)
# endif
#
# /* CHAOS_PP_CONS */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_CONS(g, ...) CHAOS_IP_CONS_I(CHAOS_PP_TYPEOF(g), CHAOS_PP_STRIP(g), (__VA_ARGS__))
#    define CHAOS_PP_CONS_ CHAOS_PP_LAMBDA(CHAOS_PP_CONS_ID)()
# else
#    define CHAOS_PP_CONS(g, x) CHAOS_IP_CONS_I(CHAOS_PP_TYPEOF(g), CHAOS_PP_STRIP(g), (x))
# endif
#
# define CHAOS_PP_CONS_ID() CHAOS_PP_CONS
#
# define CHAOS_IP_CONS_I(type, data, px) (type) CHAOS_PP_PRIMITIVE_CAT(type, _CONS)(data, CHAOS_PP_REM px)
#
# /* CHAOS_PP_ITEM */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_ITEM(type, ...) CHAOS_PP_PRIMITIVE_CAT(type, _ITEM)(__VA_ARGS__)
#    define CHAOS_PP_ITEM_ CHAOS_PP_LAMBDA(CHAOS_PP_ITEM_ID)()
# else
#    define CHAOS_PP_ITEM(type, x) CHAOS_PP_PRIMITIVE_CAT(type, _ITEM)(x)
# endif
#
# define CHAOS_PP_ITEM_ID() CHAOS_PP_ITEM
#
# /* CHAOS_PP_HEAD */
#
# define CHAOS_PP_HEAD(g) CHAOS_IP_HEAD_I(CHAOS_PP_TYPEOF(g), CHAOS_PP_STRIP(g))
# define CHAOS_PP_HEAD_ID() CHAOS_PP_HEAD
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_HEAD_ CHAOS_PP_LAMBDA(CHAOS_PP_HEAD_ID)()
# endif
#
# define CHAOS_IP_HEAD_I(type, data) CHAOS_PP_PRIMITIVE_CAT(type, _HEAD)(data)
#
# /* CHAOS_PP_TAIL */
#
# define CHAOS_PP_TAIL(g) CHAOS_IP_TAIL_I(CHAOS_PP_TYPEOF(g), CHAOS_PP_STRIP(g))
# define CHAOS_PP_TAIL_ID() CHAOS_PP_TAIL
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_TAIL_ CHAOS_PP_LAMBDA(CHAOS_PP_TAIL_ID)()
# endif
#
# define CHAOS_IP_TAIL_I(type, data) (type) CHAOS_PP_PRIMITIVE_CAT(type, _TAIL)(data)
#
# /* CHAOS_PP_IS_CONS */
#
# define CHAOS_PP_IS_CONS(g) CHAOS_IP_IS_CONS_I(CHAOS_PP_TYPEOF(g), CHAOS_PP_STRIP(g))
# define CHAOS_PP_IS_CONS_ID() CHAOS_PP_IS_CONS
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_IS_CONS_ CHAOS_PP_LAMBDA(CHAOS_PP_IS_CONS)
# endif
#
# define CHAOS_IP_IS_CONS_I(type, data) CHAOS_PP_PRIMITIVE_CAT(type, _IS_CONS)(data)
#
# /* CHAOS_PP_IS_NIL */
#
# define CHAOS_PP_IS_NIL(g) CHAOS_IP_IS_NIL_I(CHAOS_PP_TYPEOF(g), CHAOS_PP_STRIP(g))
# define CHAOS_PP_IS_NIL_ID() CHAOS_PP_IS_NIL
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_IS_NIL_ CHAOS_PP_LAMBDA(CHAOS_PP_IS_NIL)
# endif
#
# define CHAOS_IP_IS_NIL_I(type, data) CHAOS_PP_PRIMITIVE_CAT(type, _IS_NIL)(data)
#
# endif
