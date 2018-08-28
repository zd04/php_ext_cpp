#include <stdio.h>
#include <stdarg.h>
/**
 * 使用函数指针，类似于php中的回调
 * @return 
 */

//声明一个结构体
struct MyStruct;

//定义一个全局的指针
static struct MyStruct (*p)(struct MyStruct s, int a[*]) = NULL;

//声明一个函数
static void Test(void);

/**
 * 不定参数的函数
 * @param n
 * @param ...
 * @return 
 */
static int Foo(int n, ...){
    va_list ap;
    va_start(ap, n);
    
    int sum = 0;
    
    for(int i = 0; i < n; i++){
        sum += va_arg(ap, int);
    }
    
    va_end(ap);
    
    return sum;
}

int main(){
    
    //声明一个函数指针的
    void(*pf)(void) = Test;
    
    //执行一个函数指针的
    (*pf)();
    
    int (*pFunc)(int, ...) = &Foo;
    
    int result = pFunc(2,10,20,30);
    printf("result 1 = %d \n",result);
    
    int(**pp)(int, ...) = &pFunc;
    
    result = (*pp)(5,1,2,3,4,5);
    
    printf("result 2 = %d \n",result);
    
    *pp = NULL;
    
    if(pFunc == NULL){
        puts("NULL");
    }
    
    
}

struct MyStruct{
    int a;
    float f;
};

static struct MyStruct Func(struct MyStruct s, int a[]){
    printf("sum = %f\n",s.a + s.f + a[0]);
    
    return s;
}

static void Test(void){
    //全局变量p,实际上是一个函数指针
    p = Func;
    
    //字面量的结构体和数组
    p((struct MyStruct){.a = 10, .f = 0.5f},(int[]){1,2,3});
}

/**
 * 
 * @param f1
 * @param ...
 */
static void callfn(static struct MyStruct (*f1)(struct MyStruct s, int a[*]),...){
    
}