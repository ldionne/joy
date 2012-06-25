/*!
 * This file contains name mangling facilities.
 *
 * @author Louis Dionne
 */

#ifndef JOY_MANGLE_H
#define JOY_MANGLE_H

#include <chaos/preprocessor/cat.h>


/*!
 * Mangle a name.
 */
#define JOY_MANGLE(name) CHAOS_PP_CAT(joy0x, name)

/*!
 * Create a mangled name by concatenning two particules.
 */
#define JOY_MANGLE_CAT(particule1, particule2) \
    CHAOS_PP_CAT(JOY_MANGLE(particule1), particule2)

#endif /* !JOY_MANGLE_H */
