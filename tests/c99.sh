#!/bin/sh
#$Id$
#Copyright (c) 2014 Pierre Pronchery <khorben@defora.org>
#
#Redistribution and use in source and binary forms, with or without
#modification, are permitted provided that the following conditions are met:
#
# * Redistributions of source code must retain the above copyright notice, this
#   list of conditions and the following disclaimer.
# * Redistributions in binary form must reproduce the above copyright notice,
#   this list of conditions and the following disclaimer in the documentation
#   and/or other materials provided with the distribution.
#
#THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
#AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
#IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
#DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
#FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
#DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
#SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
#CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
#OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
#OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.



#variables
PROGNAME="c99.sh"
#executables
C99="../src/c99"
[ -n "$OBJDIR" ] && C99="${OBJDIR}c99"


#functions
#usage
_usage()
{
	echo "Usage: $PROGNAME [-Wc][-M backend][-o target] file..." 1>&2
	return 1
}


#main
flags=
output=
while getopts "M:Wco:" name; do
	case $name in
		M)
			flags="$flags -M $OPTARG"
			;;
		W)
			flags="$flags -W"
			;;
		c)
			;;
		o)
			output="$OPTARG"
			;;
		?)
			_usage
			exit $?
			;;
	esac
done
shift $((OPTIND - 1))
if [ $# -eq 0 ]; then
	_usage
	exit $?
fi

if [ $# -eq 1 -a -n "$output" ]; then
	target="$1"

	LD_LIBRARY_PATH="../src" $C99 $flags "$target" > "$output"
elif [ $# -ge 1 -a -z "$output" ]; then
	while [ $# -gt 0 ]; do
		target="$1"
		output="${target%.c}.o"
		shift

		LD_LIBRARY_PATH="../src" $C99 $flags "$target" > "$output"
	done
else
	_usage
	exit $?
fi
