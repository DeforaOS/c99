/* $Id$ */
/* Copyright (c) 2008 Pierre Pronchery <khorben@defora.org> */
/* This file is part of DeforaOS Devel c99 */
/* c99 is not free software; you can redistribute it and/or modify it under the
 * terms of the Creative Commons Attribution-NonCommercial-ShareAlike 3.0
 * Unported as published by the Creative Commons organization.
 *
 * c99 is distributed in the hope that it will be useful, but WITHOUT ANY
 * WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR
 * A PARTICULAR PURPOSE.  See the Creative Commons Attribution-NonCommercial-
 * ShareAlike 3.0 Unported license for more details.
 *
 * You should have received a copy of the Creative Commons Attribution-
 * NonCommercial-ShareAlike 3.0 along with c99; if not, browse to
 * http://creativecommons.org/licenses/by-nc-sa/3.0/ */



#ifndef C99_TOKENSET_H
# define C99_TOKENSET_H

# include <System.h>


/* protected */
extern TokenSet c99set_abstract_declarator;
extern TokenSet c99set_assignment_expr;
extern TokenSet c99set_block_item;
extern TokenSet c99set_block_item_list;
extern TokenSet c99set_compound_statement;
extern TokenSet c99set_declaration;
extern TokenSet c99set_declaration_list;
extern TokenSet c99set_declaration_specifiers;
extern TokenSet c99set_declarator;
extern TokenSet c99set_designation;
extern TokenSet c99set_enum_specifier;
extern TokenSet c99set_expression;
extern TokenSet c99set_expression_statement;
extern TokenSet c99set_function_definition;
extern TokenSet c99set_function_specifier;
extern TokenSet c99set_init_declarator;
extern TokenSet c99set_iteration_statement;
extern TokenSet c99set_jump_statement;
extern TokenSet c99set_keyword;
extern TokenSet c99set_identifier_list;
extern TokenSet c99set_labeled_statement;
extern TokenSet c99set_parameter_type_list;
extern TokenSet c99set_pointer;
extern TokenSet c99set_postfix_expr;
extern TokenSet c99set_primary_expr;
extern TokenSet c99set_punctuator;
extern TokenSet c99set_selection_statement;
extern TokenSet c99set_statement;
extern TokenSet c99set_storage_class_specifier;
extern TokenSet c99set_struct_or_union_specifier;
extern TokenSet c99set_type_qualifier;
extern TokenSet c99set_type_qualifier_list;
extern TokenSet c99set_type_specifier;
extern TokenSet c99set_typedef_name;
extern TokenSet c99set_unary_expr;

#endif /* !C99_TOKENSET_H */
