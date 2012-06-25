/*!
 * This file defines a macro to parse a sequence of sequences.
 *
 * @author Louis Dionne
 */

#ifndef JOY_PARSE_H
#define JOY_PARSE_H

#include <joy/internal/execute.h>

#include <chaos/preprocessor/recursion/expr.h>
#include <chaos/preprocessor/control/branch.h>
#include <chaos/preprocessor/tuple/elem.h>
#include <chaos/preprocessor/seq/core.h>
#include <chaos/preprocessor/seq/fold_left.h>
#include <chaos/preprocessor/seq/to_tuple.h>


/*!
 * Parse a sequence of sequences and call a provided callback on each sequence.
 *
 * @note The callback must be a macro with the following signature:
 *       callback(s, context, aux_data, current_sequence, seen)
 *
 * The callback must use the JOY_PARSE_CALLBACK_RESULT macro to return.
 */
#define JOY_PARSE(callback, aux_data, sequences) \
    JOY_PARSE_S(CHAOS_PP_STATE(), callback, aux_data, sequences)

#define JOY_PARSE_S(s, callback, aux_data, sequences)                          \
    CHAOS_PP_TUPLE_ELEM(5, 4, CHAOS_PP_EXPR_S(s) (                             \
        CHAOS_PP_SEQ_FOLD_LEFT_S(s,                                            \
            JOY_I_PARSE_ONE, sequences,                                        \
            JOY_I_PARSE_INFO(                                                  \
            /*whether this sequence is a parse context*/ 0,                    \
            /*callback to use when parsing arguments*/ callback,               \
            /*the current parse context*/ ~,                                   \
            JOY_PARSE_CALLBACK_RESULT(                                         \
                /*auxiliary data*/ aux_data,                                   \
                /*sequences parsed up to now*/ CHAOS_PP_SEQ_NIL()              \
            )                                                                  \
            )                                                                  \
        )                                                                      \
    ))                                                                         \
/**/

/*!
 * Parse one sequence.
 */
#define JOY_I_PARSE_ONE(s, sequence, parse_info)                               \
    JOY_II_PARSE_ONE(s, sequence,                                              \
        CHAOS_PP_TUPLE_ELEM(5, 0, parse_info),                                 \
        CHAOS_PP_TUPLE_ELEM(5, 1, parse_info),                                 \
        CHAOS_PP_TUPLE_ELEM(5, 2, parse_info),                                 \
        CHAOS_PP_TUPLE_ELEM(5, 3, parse_info),                                 \
        CHAOS_PP_TUPLE_ELEM(5, 4, parse_info)                                  \
    )                                                                          \
/**/

#define JOY_II_PARSE_ONE(s, sequence, is_parse_context, callback,              \
                            context, aux_data, seen)                           \
        /* The current sequence introduces a new parse context; exchange       \
           the current context with the one embedded in the sequence and       \
           set the is_parse_context flag to false. */                          \
    CHAOS_PP_BRANCH(0xIF) (is_parse_context) (                                 \
        JOY_I_PARSE_INFO(                                                      \
            0,                                                                 \
            callback,                                                          \
            sequence,                                                          \
            JOY_PARSE_CALLBACK_RESULT(aux_data, seen)                          \
        )                                                                      \
                                                                               \
        /* The next sequence introduces a new parse context; set the flag      \
           so we know we are facing a context when parsing the next sequence. */ \
    ) (0xELIF) (JOY_I_NEXT_IS_PARSE_CONTEXT(sequence)) (                       \
        JOY_I_PARSE_INFO(                                                      \
            1,                                                                 \
            callback,                                                          \
            context,                                                           \
            JOY_PARSE_CALLBACK_RESULT(aux_data, seen)                          \
        )                                                                      \
                                                                               \
        /* The sequence is an argument sequence to parse; use the provided     \
           callback to process it. */                                          \
    ) (0xELSE) (                                                               \
        JOY_I_PARSE_INFO(                                                      \
            is_parse_context ,                                                 \
            callback,                                                          \
            context,                                                           \
            callback(s, context, aux_data, sequence, seen)                     \
        )                                                                      \
    ) (0xENDIF)                                                                \
/**/

/*!
 * Hold the parse information during parsing.
 */
#define JOY_I_PARSE_INFO(is_parse_context, callback, context, callback_result) \
    (                                                                          \
        is_parse_context,                                                      \
        callback,                                                              \
        context,                                                               \
        JOY_PAIR_FIRST(callback_result),                                       \
        JOY_PAIR_SECOND(callback_result)                                       \
    )                                                                          \
/**/

/*!
 * Create a parse context. A parse context is a data element that will
 * be picked up by the parser when it is encountered. The data element will
 * stay the same until another one is encountered.
 */
#define JOY_PARSE_CONTEXT(context) (CHAOS_PP_SEQ_NIL()) (context)

/*!
 * Return whether the next sequence introduces a new parse context.
 */
#define JOY_I_NEXT_IS_PARSE_CONTEXT(sequence) \
    CHAOS_PP_SEQ_IS_NIL(sequence)

/*!
 * Macro used to return the result from a callback.
 *
 * @param aux_data Auxiliary data to be passed to the callback the next
 *                 time it is called. It allows to share state between
 *                 calls when parsing.
 * @param accumulated Accumulated sequence of parsed sequences.
 */
#define JOY_PARSE_CALLBACK_RESULT(aux_data, accumulated) \
    JOY_PAIR(aux_data, accumulated)

/*!
 * Prepare a sequence of instructions to be executed by JOY_EXECUTE.
 */
#define JOY_PARSE_TO_EXEC(instructions) \
    JOY_PARSE_TO_EXEC_S(CHAOS_PP_STATE(), instructions)

#define JOY_PARSE_TO_EXEC_S(s, instructions)                                   \
    JOY_PARSE_S(s,                                                             \
        JOY_I_PARSE_TO_EXEC_CALLBACK, ~, instructions                          \
    )                                                                          \
/**/

/*!
 * Set the instruction to be applied to all of the subsequent sequences of
 * arguments or until another JOY_FROM_NOW_ON is encountered.
 *
 * @param action A macro taking the recursion state and all the arguments
 *               of each sequence as arguments.
 */
#define JOY_FROM_NOW_ON(action) JOY_PARSE_CONTEXT(action)

/*!
 * Callback used when parsing a sequence of instructions. Creates a valid
 * instruction with the current action.
 */
#define JOY_I_PARSE_TO_EXEC_CALLBACK(s, context, aux_data, args, seen)         \
    JOY_PARSE_CALLBACK_RESULT(                                                 \
        aux_data, seen (JOY_INSTRUCTION(context, args))                        \
    )                                                                          \
/**/

#endif /* !JOY_PARSE_H */
