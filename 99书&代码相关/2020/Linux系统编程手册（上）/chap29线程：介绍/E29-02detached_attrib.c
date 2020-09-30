pthread_t thr;
pthread_attr_t attr;
int s;

s = pthread_attr_init(&attr);  // Assigns default values
if (s != 0)
    ;

s = pthread_attr_setdetachstate(&attr, PTHRED_CREATE_DETACHED);
if (s != 0)
;

S = pthread_create(&thr, &attr, thread_Func, (void*)1);
if (s != 0)
;

s = pthread_attr_destroy(&attr);   // No longer needed
if (s != 0)
;
