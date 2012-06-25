/*!
 * This file defines a macro to compare identifiers for (in)equality.
 */

#ifndef JOY_COMPARE_H
#define JOY_COMPARE_H

# include <chaos/preprocessor/control/iif.h>
# include <chaos/preprocessor/detection/is_nullary.h>
# include <chaos/preprocessor/logical/bitand.h>
# include <chaos/preprocessor/logical/compl.h>


/*!
 * Compare two identifiers with a common prefix.
 *
 * @note This is a (very) slightly modified version of the CHAOS_PP_COMPARE()
 *       macro of the Chaos preprocessor library. All the credit goes to
 *       the Chaos library for this macro.
 */
#define JOY_COMPARE(prefix, a, b)                                              \
    CHAOS_PP_IIF(                                                              \
        CHAOS_PP_BITAND                                                        \
            (CHAOS_PP_IS_NULLARY(prefix ## a(())))                             \
            (CHAOS_PP_IS_NULLARY(prefix ## b(())))                             \
    )(                                                                         \
        CHAOS_PP_COMPL(CHAOS_PP_IS_NULLARY(                                    \
            prefix ## a(                                                       \
                prefix ## b                                                    \
            )(())                                                              \
        )),                                                                    \
        0                                                                      \
    )                                                                          \
/**/

#endif /*! JOY_COMPARE_H */
