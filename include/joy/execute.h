/*!
 * This file defines a macro to execute a sequence of instructions.
 *
 * @author Louis Dionne
 */

#ifndef JOY_EXECUTE_H
#define JOY_EXECUTE_H

#include <joy/pair.h>

#include <chaos/preprocessor/recursion/expr.h>
#include <chaos/preprocessor/seq/transform.h>
#include <chaos/preprocessor/seq/fold_left.h>
#include <chaos/preprocessor/seq/to_tuple.h>


/*!
 * Create an instruction to be executed by JOY_EXECUTE.
 *
 * @param instruction A macro to be executed.
 * @param arguments A sequence of arguments to the macro.
 * @note The recursion state is passed to the macro as its first argument.
 */
#define JOY_INSTRUCTION(instruction, arguments) \
    JOY_PAIR(instruction, arguments)

/*!
 * Transform a sequence, executing each element as an instruction.
 */
#define JOY_EXECUTE_TRANSFORM(instructions) \
    JOY_EXECUTE_TRANSFORM_S(CHAOS_PP_STATE(), instructions)

#define JOY_EXECUTE_TRANSFORM_S(s, instructions)                               \
    CHAOS_PP_EXPR_S(s)(CHAOS_PP_SEQ_TRANSFORM_S(s,                             \
        JOY_I_EXECUTE_TRANSFORM, instructions, ~                               \
    ))                                                                         \
/**/

#define JOY_I_EXECUTE_TRANSFORM(s, instruction, useless)                       \
    JOY_EXECUTE_INSTRUCTION_S(s,                                               \
        JOY_PAIR_FIRST(instruction),                                           \
        JOY_PAIR_SECOND(instruction)                                           \
    )                                                                          \
/**/

/*!
 * Fold a sequence, executing each element as an instruction.
 */
#define JOY_EXECUTE_FOLD(initial_state, instructions) \
    JOY_EXECUTE_FOLD_S(CHAOS_PP_STATE(), initial_state, instructions)

#define JOY_EXECUTE_FOLD_S(s, initial_state, instructions)                     \
    CHAOS_PP_EXPR_S(s)(CHAOS_PP_SEQ_FOLD_LEFT_S(s,                             \
        JOY_I_EXECUTE_FOLD, instructions, initial_state                        \
    ))                                                                         \
/**/

#define JOY_I_EXECUTE_FOLD(s, instruction, state)                              \
    JOY_EXECUTE_INSTRUCTION_S(s,                                               \
        JOY_PAIR_FIRST(instruction),                                           \
        (state) JOY_PAIR_SECOND(instruction)                                   \
    )                                                                          \
/**/

/*!
 * Execute a single instruction.
 */
#define JOY_EXECUTE_INSTRUCTION(instruction, arguments) \
    JOY_EXECUTE_INSTRUCTION_S(CHAOS_PP_STATE(), instruction, arguments)

#define JOY_EXECUTE_INSTRUCTION_S(s, instruction, arguments)                   \
    JOY_I_EXECUTE_INSTRUCTION(                                                 \
        instruction CHAOS_PP_SEQ_TO_TUPLE((s) arguments)                       \
    )                                                                          \
/**/

#define JOY_I_EXECUTE_INSTRUCTION(x) x

#endif /* !JOY_EXECUTE_H */
