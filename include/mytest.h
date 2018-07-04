/*************************************************************************
	> File Name: mytest.h
	> Author: 
	> Mail: 
	> Created Time: 2017年12月10日 星期日 15时21分24秒
 ************************************************************************/

#ifndef _MYTEST_H
#define _MYTEST_H
typedef struct count{
    int Righttime;
    int Wrongtime;
    int alltime;
}Count, *Pcount;
#define TEST(a,b) \
        void name##a##_##b(Pcount __count);\
        int p##a##_##b = Runfun(name##a##_##b, #a, #b);\
        void name##a##_##b(Pcount __count)


#define EXPECT_EQ(a, b) \
        a == b ? __count -> Righttime++ : __count -> Wrongtime++;\
        __count -> alltime++;

int Runfun(void (*func)(Pcount), const char * str1, const char * str2) {
    Count mycount = {0, 0 , 0};
    printf ("\033[32m[Run     ]%s.%s", str1, str2);
    func(&mycount);
    if (mycount.Wrongtime == 0) {
        printf ("\033[32m[     OK ]%s.%s", str1,str2);
    }
    else {
        printf ("\033[32m[   fault]%s.%s %dpassed  %dwrong   %dtested", str1, str2, mycount.Righttime, mycount.Wrongtime, mycount.alltime);
    }
    return 0;
}
#endif
