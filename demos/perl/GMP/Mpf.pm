# GMP mpf module.

# Copyright 2001 Free Software Foundation, Inc.
#
# This file is part of the GNU MP Library.
#
# The GNU MP Library is free software; you can redistribute it and/or modify
# it under the terms of the GNU Lesser General Public License as published
# by the Free Software Foundation; either version 2.1 of the License, or (at
# your option) any later version.
#
# The GNU MP Library is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
# or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public
# License for more details.
#
# You should have received a copy of the GNU Lesser General Public License
# along with the GNU MP Library; see the file COPYING.LIB.  If not, write to
# the Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston,
# MA 02111-1307, USA.


package GMP::Mpf;

require GMP;
require Exporter;
@ISA = qw(GMP Exporter);
@EXPORT = qw();
@EXPORT_OK = qw();
%EXPORT_TAGS = ('all' => [qw(
			     ceil floor get_default_prec get_prec mpf mpf_eq
			     mpf_get_str reldiff set_default_prec set_prec
			     trunc)],
		'constants'   => [@EXPORT],
		'noconstants' => [@EXPORT]);
Exporter::export_ok_tags('all');

use overload
    '+'   => \&overload_add,     '+='  => \&overload_addeq,
    '-'   => \&overload_sub,     '-='  => \&overload_subeq,
    '*'   => \&overload_mul,     '*='  => \&overload_muleq,
    '/'   => \&overload_div,     '/='  => \&overload_diveq,
    '**'  => \&overload_pow,     '**=' => \&overload_poweq,
    '<<'  => \&overload_lshift,  '<<=' => \&overload_lshifteq,
    '>>'  => \&overload_rshift,  '>>=' => \&overload_rshifteq,

    'bool' => \&overload_bool,
    'not'  => \&overload_not,
    '!'    => \&overload_not,
    '<=>'  => \&overload_spaceship,
    '++'   => \&overload_inc,
    '--'   => \&overload_dec,
    'abs'  => \&overload_abs,
    'neg'  => \&overload_neg,
    'sqrt' => \&overload_sqrt,
    '='    => \&overload_copy,
    '""'   => \&overload_string;

sub import {
  foreach (@_) {
    if ($_ eq ':constants') {
      overload::constant ('integer' => \&overload_constant,
			  'binary'  => \&overload_constant,
			  'float'   => \&overload_constant);
    } elsif ($_ eq ':noconstants') {
      overload::remove_constant ('integer' => \&overload_constant,
				 'binary'  => \&overload_constant,
				 'float'   => \&overload_constant);
    }
  }
  goto &Exporter::import;
}


sub overload_string {
  my ($str, $exp) = mpf_get_str($_[0], 10, 0);
  return GMP::mpf_get_str_convert (10, $str, $exp);
}

1;
__END__


# Local variables:
# perl-indent-level: 2
# End:
