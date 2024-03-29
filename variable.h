#ifndef RUBY_TOPLEVEL_VARIABLE_H                         /*-*-C-*-vi:se ft=c:*/
#define RUBY_TOPLEVEL_VARIABLE_H
/**
 * @author     Ruby developers <ruby-core@ruby-lang.org>
 * @copyright  This  file  is   a  part  of  the   programming  language  Ruby.
 *             Permission  is hereby  granted,  to  either redistribute  and/or
 *             modify this file, provided that  the conditions mentioned in the
 *             file COPYING are met.  Consult the file for details.
 */

/* per-object */

#include "shape.h"

struct gen_ivtbl {
#if !SHAPE_IN_BASIC_FLAGS
    uint16_t shape_id;
#endif
    union {
        struct {
            uint32_t numiv;
            VALUE ivptr[1];
        } shape;
        struct {
            st_table *table;
        } complex;
    } as;
};

int rb_ivar_generic_ivtbl_lookup(VALUE obj, struct gen_ivtbl **);

#if !SHAPE_IN_BASIC_FLAGS
shape_id_t rb_generic_shape_id(VALUE obj);
#endif


#endif /* RUBY_TOPLEVEL_VARIABLE_H */
