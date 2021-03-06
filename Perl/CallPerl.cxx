#include <std.h>
#include <EXTERN.h>
#include <perl.h>

static PerlInterpreter* my_perl;

void
call_PerlSubs (void)
{
  dSP;

  ENTER;
  SAVETMPS;
  PUSHMARK (SP);

  XPUSHs (sv_2mortal(newSVpv("Surya.Kiran.Gullapalli", 0)));
  PUTBACK;

  int count = call_pv ("func_return_array", G_ARRAY);

  SPAGAIN;

  cout << "Number of items returned: " << count << endl;
  
  for (int i = 0; i < count; ++i) {
    cout << '\t' << POPp << endl;
  }

  PUTBACK;
  FREETMPS;
  LEAVE;
}

int main (int argc, char** argv, char** env)
{
  char* command_line[2] = {"", "/home/suki/Projects/SourceArea/CodeSamples/Perl/CallPerl_files/CallPerl.pl"};
  
  PERL_SYS_INIT3(&argc, &argv, &env);
  my_perl = perl_alloc();
  perl_construct (my_perl);
  perl_parse (my_perl, NULL, 2, command_line, (char **)NULL);
  PL_exit_flags |= PERL_EXIT_DESTRUCT_END;
  call_PerlSubs ();

  perl_destruct(my_perl);
  perl_free(my_perl);
  PERL_SYS_TERM();
  
}
