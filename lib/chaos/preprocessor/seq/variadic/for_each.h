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
# ifndef CHAOS_PREPROCESSOR_SEQ_VARIADIC_FOR_EACH_H
# define CHAOS_PREPROCESSOR_SEQ_VARIADIC_FOR_EACH_H
#
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/facilities/optional.h>
# include <chaos/preprocessor/lambda/ops.h>
# include <chaos/preprocessor/recursion/expr.h>
# include <chaos/preprocessor/seq/for_each.h>
# include <chaos/preprocessor/seq/zip.h>
#
# /* CHAOS_PP_VARIADIC_SEQ_FOR_EACH */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_VARIADIC_SEQ_FOR_EACH(macro, ...) CHAOS_PP_VARIADIC_SEQ_FOR_EACH_S(CHAOS_PP_STATE(), macro, __VA_ARGS__)
#    define CHAOS_PP_VARIADIC_SEQ_FOR_EACH_ID() CHAOS_PP_VARIADIC_SEQ_FOR_EACH
#    define CHAOS_PP_VARIADIC_SEQ_FOR_EACH_ CHAOS_PP_LAMBDA(CHAOS_PP_VARIADIC_SEQ_FOR_EACH_ID)()
# endif
#
# /* CHAOS_PP_VARIADIC_SEQ_FOR_EACH_S */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_VARIADIC_SEQ_FOR_EACH_S(s, macro, ...) CHAOS_PP_SEQ_FOR_EACH_S(s, macro, CHAOS_PP_SEQ_ZIP(CHAOS_PP_NON_OPTIONAL(__VA_ARGS__)) CHAOS_PP_EXPOSE(CHAOS_PP_PACK_OPTIONAL(__VA_ARGS__)))
#    define CHAOS_PP_VARIADIC_SEQ_FOR_EACH_S_ID() CHAOS_PP_VARIADIC_SEQ_FOR_EACH_S
#    define CHAOS_PP_VARIADIC_SEQ_FOR_EACH_S_ CHAOS_PP_LAMBDA(CHAOS_PP_VARIADIC_SEQ_FOR_EACH_S_ID)()
# endif
#
# endif
