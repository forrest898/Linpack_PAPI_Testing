#include <stdio.h>
#include <papi.h>

int main(int argc, char** argv) {

  int retval, EventSet = PAPI_NULL;
  long long values[2];

  retval = PAPI_library_init(PAPI_VER_CURRENT);
  if(retval != PAPI_VER_CURRENT) {
    printf("\nError initializing PAPI\n");
    return 1;
  }

  if(PAPI_create_eventset(&EventSet) != PAPI_OK) {
    printf("\nError creating EventSet\n");
    return 1;
  }

  if(PAPI_add_event(EventSet, PAPI_TOT_INS) != PAPI_OK) {
    printf("\nError adding event\n" );
    return 1;
  }

  if(PAPI_add_event(EventSet, PAPI_TOT_CYC) != PAPI_OK) {
    printf("\nError adding event\n" );
    return 1;
  }

  if(PAPI_start(EventSet) != PAPI_OK) {
    printf("\nError starting PAPI\n" );
    return 1;
  }
  //start = PAPI_get_real_usec();

  for(int i=0; i < 1000000; i++) {
    printf("HelloWorld");
  }

  if(PAPI_stop(EventSet, values) != PAPI_OK) {
    printf("\nError Closing PAPI\n");
    return 1;
  }

  printf("\n%lld    %lld      %lf\n", values[0], values[1],((double)values[0]/(double)values[1]));

  //end = PAPI_get_real_usec();

  //printf("\nTotal Time: %lld", (end-start));

  return 0;
}
