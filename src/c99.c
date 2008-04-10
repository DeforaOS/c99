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



#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include "common.h"
#include "c99.h"


/* public */
/* functions */
/* c99_new */
static Cpp * _new_cpp(C99Prefs * prefs, char const * pathname);
static char * _new_outfile(int flags, char const * outfile,
		char const * pathname);

C99 * c99_new(C99Prefs * prefs, char const * pathname)
{
	C99 * c99;

	if((c99 = object_new(sizeof(*c99))) == NULL)
		return NULL;
	memset(c99, 0, sizeof(*c99));
	c99->flags = prefs->flags;
	if((c99->cpp = _new_cpp(prefs, pathname)) == NULL)
	{
		object_delete(c99);
		return NULL;
	}
	c99->outfile = _new_outfile(prefs->flags, prefs->outfile, pathname);
	if(c99->outfile != NULL)
		c99->outfp = (c99->outfile[0] == '\0') ? stdout
			: fopen(c99->outfile, "w");
	else
		c99->outfp = NULL;
	c99->optlevel = prefs->optlevel;
	c99->code = code_new();
	/* abort if there was an error */
	if(c99->outfile == NULL || c99->outfp == NULL || c99->code == NULL)
	{
		c99_delete(c99);
		return NULL;
	}
	return c99;
}

static Cpp * _new_cpp(C99Prefs * prefs, char const * pathname)
{
	Cpp * cpp;
	size_t i;
	size_t j;
	size_t k;

	if((cpp = cpp_new(pathname, CPP_FILTER_TRIGRAPH)) == NULL)
		return NULL;
	for(i = 0; i < prefs->paths_cnt; i++)
		if(cpp_path_add(cpp, prefs->paths[i]) != 0)
			break;
	for(j = 0; j < prefs->defines_cnt; j++)
		if(cpp_define_add(cpp, prefs->defines[j], NULL) != 0)
			break;
	for(k = 0; k < prefs->undefines_cnt; k++)
		if(cpp_define_remove(cpp, prefs->undefines[k]) != 0)
			break;
	if(i != prefs->paths_cnt || j != prefs->defines_cnt
			|| k != prefs->undefines_cnt)
	{
		cpp_delete(cpp);
		return NULL;
	}
	return cpp;
}

static char * _new_outfile(int flags, char const * outfile,
		char const * pathname)
{
	char * ret;
	size_t len;

	if(flags & C99PREFS_c && pathname != NULL)
	{
		if((len = strlen(pathname)) < 3 || pathname[len - 2] != '.'
				|| pathname[len - 1] != 'c')
		{
			error_set_code(1, "%s", strerror(EINVAL));
			return NULL;
		}
		if((ret = strdup(pathname)) == NULL)
		{
			error_set_code(1, "%s", strerror(errno));
			return NULL;
		}
		ret[len - 1] = 'o';
		return ret;
	}
	if(flags & C99PREFS_E && outfile == NULL)
		outfile = "";
	else if(outfile == NULL)
		outfile = "a.out";
	if((ret = strdup(outfile)) == NULL)
	{
		error_set_code(1, "%s", strerror(errno));
		return NULL;
	}
	return ret;
}


/* c99_delete */
int c99_delete(C99 * c99)
{
	int ret = 0;

	cpp_delete(c99->cpp);
	if(c99->outfp != NULL && fclose(c99->outfp) != 0)
		ret = error_set_code(1, "%s: %s", c99->outfile,
				strerror(errno));
	free(c99->outfile);
	if(c99->token != NULL)
		token_delete(c99->token);
	code_delete(c99->code);
	object_delete(c99);
	return ret;
}
