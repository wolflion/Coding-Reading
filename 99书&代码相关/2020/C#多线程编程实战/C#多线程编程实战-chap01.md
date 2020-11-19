### chap1、线程基础（21/217）

#### 1.1、简介

#### 1.2、使用C#创建线程

```c#
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Threading;  //新增

namespace LionelPro
{
    class Program
    {
        static void Main(string[] args)
        {
            //构造一个线程时，ThreadStart或ParameterizedThreadStart的实例委托会传给构造函数。
            Thread t = new Thread(PrintNumbers);
            t.Start();

            PrintNumbers();
        }

        static void PrintNumbers()   // 2个引用，被main()中的主线程用了，又被thread类创建的给调用了
        {
            Console.WriteLine("Starting...");
            for(int i=1;i<10;i++)
            {
                Console.WriteLine(i);
            }
        }
    }
}

```



#### 1.3、暂停线程

+ 用的是`Thread.Sleep()`的方法，不算高级

```c#
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Threading;  //新增

namespace LionelPro
{
    class Program
    {
        static void Main(string[] args)
        {
            //构造一个线程时，ThreadStart或ParameterizedThreadStart的实例委托会传给构造函数。
            Thread t = new Thread(PrintNumberWithDelay);
            t.Start();

            PrintNumbers();
        }

        static void PrintNumbers()
        {
            Console.WriteLine("Starting...");
            for (int i = 1; i < 10; i++)
            {
                Console.WriteLine(i);
            }
        }

        static void PrintNumberWithDelay()
        {
            Console.WriteLine("Starting...");
            for (int i = 1; i < 10; i++)
            {
                Thread.Sleep(TimeSpan.FromSeconds(2));  //每次休眠2秒钟
                Console.WriteLine(i);
            }
        }
    }
}

```



#### 1.4、线程等待

+ 用的是`t.join()`方法。

```c#
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Threading;  //新增

namespace LionelPro
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Starting...");
            //构造一个线程时，ThreadStart或ParameterizedThreadStart的实例委托会传给构造函数。
            Thread t = new Thread(PrintNumberWithDelay);
            t.Start();
            t.Join();  // 允许我们等待直到线程t完成。当线程t完成时，主程序会继续运行。
            Console.WriteLine("Thread completed");
        }

        static void PrintNumberWithDelay()
        {
            Console.WriteLine("Starting...");
            for (int i = 1; i < 10; i++)
            {
                Thread.Sleep(TimeSpan.FromSeconds(2));  //每次休眠2秒钟
                Console.WriteLine(i);
            }
        }
    }
}

```



#### 1.5、终止线程

+ 书中代码写错了吧，要么是重名，要么是多写了一个(PrintNumber)。
+ ` t.Abort();` // 相当于给线程注入了ThreadAbortException方法，导致线程被终结。【Thread.ResetAbort()来拒绝被终止】  **可以用其它方法，比如CancellationToken方法来取消线程的执行**。

```c#
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Threading;  //新增

namespace LionelPro
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Starting program...");
            //构造一个线程时，ThreadStart或ParameterizedThreadStart的实例委托会传给构造函数。
            Thread t = new Thread(PrintNumberWithDelay);
            t.Start();
            Thread.Sleep(TimeSpan.FromSeconds(6));
            t.Abort(); // 相当于给线程注入了ThreadAbortException方法，导致线程被终结。【Thread.ResetAbort()来拒绝被终止】
            Console.WriteLine("A thread has been aborted");

            Thread t1 = new Thread(PrintNumbers);
            t1.Start();

            PrintNumbers();
        }

        static void PrintNumberWithDelay()
        {
            Console.WriteLine("Starting...");
            for (int i = 1; i < 10; i++)
            {
                Thread.Sleep(TimeSpan.FromSeconds(2));  //每次休眠2秒钟
                Console.WriteLine(i);
            }
        }

        static void PrintNumbers()
        {
            Console.WriteLine("Starting...");
            for (int i = 1; i < 10; i++)
            {
                Console.WriteLine(i);
            }
        }
    }
}

```



#### 1.6、检测线程状态

+ 线程状态位于Thread对象的ThreadState属性中。ThreadState属性是个C#枚举对象。刚开始线程状态为ThreadState.Unstartee。然后我们启动线程，并估计在一个周期为30次迭代的区间中，线程状态会从ThreadState.Running变为ThreadState.WaitSleepJoin。
+ **可以增加迭代次数**。
+ 终止第一个线程后，线程状态为ThreadState.Aborted，程序也有可能会打印出ThreadState.AbortRequested状态。
+ 第二个线程t2成功完成并且状态为ThreadState.Stopped。

```c#
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Threading;  //新增

namespace LionelPro
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Starting program...");
            //构造一个线程时，ThreadStart或ParameterizedThreadStart的实例委托会传给构造函数。
            Thread t = new Thread(PrintNumberWithStatus);
            Thread t2 = new Thread(DoNothing);
            Console.WriteLine(t.ThreadState.ToString());
            t2.Start();
            t.Start();
            for(int i=1;i<30;i++)
            {
                Console.WriteLine(t.ThreadState.ToString());
            }
            
            Thread.Sleep(TimeSpan.FromSeconds(6));
            t.Abort(); // 相当于给线程注入了ThreadAbortException方法，导致线程被终结。【Thread.ResetAbort()来拒绝被终止】
            Console.WriteLine("A thread has been aborted");
            Console.WriteLine(t.ThreadState.ToString());
            Console.WriteLine(t2.ThreadState.ToString());
        }

        static void PrintNumberWithStatus()
        {
            Console.WriteLine("Starting...");
            Console.WriteLine(Thread.CurrentThread.ThreadState.ToString());
            for (int i = 1; i < 10; i++)
            {
                Thread.Sleep(TimeSpan.FromSeconds(2));  //每次休眠2秒钟
                Console.WriteLine(i);
            }
        }

        static void DoNothing()
        {
            Thread.Sleep(TimeSpan.FromSeconds(2));
        }
    }
}

```



#### 1.7、线程优先级

+ *代码没看呢*

```c#
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Threading;  //新增
using System.Diagnostics; //新增

namespace LionelPro
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Current thread priority:{0}", Thread.CurrentThread.Priority);
            Console.WriteLine("Running on all cores available");
            RunThreads();
            Thread.Sleep(TimeSpan.FromSeconds(2));
            Console.WriteLine("Running on a single core");
            Process.GetCurrentProcess().ProcessorAffinity = new IntPtr(1);
            RunThreads();
        }
      
        class ThreadSample
        {
            private bool _isStopped = false;
            public void Stop()
            {
                _isStopped = true;
            }

            public void CountNumbers()
            {
                long counter = 0;
                while(!_isStopped)
                {
                    counter++;
                }
                Console.WriteLine("{0} with {1，11} priority " + "has a count = {2,13}", Thread.CurrentThread.Name, Thread.CurrentThread.Priority, counter.ToString("NO"));
            }
        }
        static void RunThreads()
        {
            var sample = new ThreadSample();
        }
   

    }
}

```



#### 1.8、前台线程和后台线程

+ *代码没看呢*

```c#
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Threading;  //新增

namespace LionelPro
{
    class Program
    {
        static void Main(string[] args)
        {
            var sampleForeground = new ThreadSample(10);
            var sampleBackground = new ThreadSample(10);

            var threadOne = new Thread(sampleForeground.CountNumbers);
            threadOne.Name = "ForegroundThread";

            var threadTwo = new Thread(sampleBackground.CountNumbers);
            threadTwo.Name = "BackgroundThread";
            threadTwo.IsBackground = true;

            threadOne.Start();
            threadTwo.Start();
        }
      

        class ThreadSample
        {
            private readonly int _iterations;

            public ThreadSample(int iterations)
            {
                _iterations = iterations;
            }

            public void CountNumbers()
            {
                for(int i=1;i<=_iterations;i++)
                {
                    Thread.Sleep(TimeSpan.FromSeconds(0.5));
                    Console.WriteLine("{0} prints {1}", Thread.CurrentThread.Name, i);
                }
            }
        }

    }
}

```



#### 1.9、向线程传递参数

+ *代码没细看*

```c#
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Threading;  //新增

namespace LionelPro
{
    class Program
    {
        static void Main(string[] args)
        {
            var sample = new ThreadSample(10);

            var threadOne = new Thread(sample.CountNumbers);
            threadOne.Name = "ThreadOne";
            threadOne.Start();
            threadOne.Join();
            Console.WriteLine("----------------------");

            var threadTwo = new Thread(Count);
            threadTwo.Name = "ThreadTwo";
            threadTwo.Start(8);
            threadTwo.Join();
            Console.WriteLine("----------------------");

            var threadThree = new Thread(()=>CountNumbers(12));
            threadThree.Name = "ThreadThree";
            threadThree.Start();
            threadThree.Join();
            Console.WriteLine("----------------------");

            int i = 10;
            var threadFour = new Thread(() => PrintNumber(i));

            i = 20;
            var threadFive = new Thread(() => PrintNumber(i));
            threadFour.Start();
            threadFive.Start();
        }
      
        static void CountNumbers(int iterations)
        {
            for(int i=1;i<=iterations;i++)
            {
                Thread.Sleep(TimeSpan.FromSeconds(0.5));
                Console.WriteLine("{0} prints {1}", Thread.CurrentThread.Name, i);
            }
        }

        static void PrintNumber(int number)
        {
            Console.WriteLine(number);
        }

        static void Count(object iterations)
        {
            CountNumbers((int)iterations);
        }
        

        class ThreadSample
        {
            private readonly int _iterations;

            public ThreadSample(int iterations)
            {
                _iterations = iterations;
            }

            public void CountNumbers()
            {
                for(int i=1;i<=_iterations;i++)
                {
                    Thread.Sleep(TimeSpan.FromSeconds(0.5));
                    Console.WriteLine("{0} prints {1}", Thread.CurrentThread.Name, i);
                }
            }
        }

    }
}

```



#### 1.10、使用C#中的lock关键字

+ Counter类并不是线程安全的

```c#
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Threading;  //新增

namespace LionelPro
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Incorrect counter");
            var c = new Counter();

            var t1 = new Thread(() => TestCounter(c));
            var t2 = new Thread(() => TestCounter(c));
            var t3 = new Thread(() => TestCounter(c));
            t1.Start();
            t2.Start();
            t3.Start();
            t1.Join();
            t2.Join();
            t3.Join();

            Console.WriteLine("Total count: {0}", c.Count);
            Console.WriteLine("-------------------------");
            Console.WriteLine("Correct counter");

            var c1 = new CounterWithLock();
            t1 = new Thread(() => TestCounter(c));
            t2 = new Thread(() => TestCounter(c));
            t3 = new Thread(() => TestCounter(c));
            t1.Start();
            t2.Start();
            t3.Start();
            t1.Join();
            t2.Join();
            t3.Join();
            Console.WriteLine("Total count: {0}", c1.Count);
        }

        abstract class CounterBase
        {
            public abstract void Increment();
            public abstract void Decrement();
        }

        class Counter:CounterBase   //Counter类并不是线程安全的
        {
            public int Count { get; private set; }
            public override void Increment()
            {
                Count++;
            }
            public override void Decrement()
            {
                Count--;
            }
        }

        class CounterWithLock:CounterBase
        {
            private readonly object _synRoot = new object();
            public int Count { get; private set; }

            public override void Increment()
            {
                lock(_synRoot)
                {
                    Count++;
                }
            }

            public override void Decrement()
            {
                lock (_synRoot)
                {
                    Count--;
                }
            }
        }

        static void TestCounter(CounterBase c)
        {
            for(int i=0;i<100000;i++)
            {
                c.Increment();
                c.Decrement();
            }
        }
    }
}

```



#### 1.11、使用Monitor类锁定资源

+ *没太花时间看*

```c#
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Threading;  //新增

namespace LionelPro
{
    class Program
    {
        static void Main(string[] args)
        {
            object lock1 = new object();
            object lock2 = new object();

            new Thread(() => LockTooMuch(lock1, lock2)).Start();

            lock(lock2)
            {
                Thread.Sleep(1000);
                Console.WriteLine("Monitor.TryEnter allows not to get stuck, returning false after a specified timeout is elapsed");
                if(Monitor.TryEnter(lock1,TimeSpan.FromSeconds(5)))
                {
                    Console.Write("Acquired a protected resource successfuly");
                }
                else
                {
                    Console.Write("Timeout acquiring a  resource !");
                }
            }


            new Thread(() => LockTooMuch(lock1, lock2)).Start();
            Console.WriteLine("----------------------------");

            lock (lock2)
            {
                Console.WriteLine("This will be a deadlock!");
                Thread.Sleep(1000);

                lock(lock1)
                {
                    Console.WriteLine("Acquired a protected resource successfully");
                }

            }


        }

       static void LockTooMuch(object lock1, object lock2)
        {
            lock (lock1)
            {
                Thread.Sleep(1000);
                lock (lock2) ;
            }
        }
      

    }
}

```



#### 1.12、处理异常

+ *没看内容呢*

```c#
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Threading;  //新增

namespace LionelPro
{
    class Program
    {
        static void Main(string[] args)
        {

            var t = new Thread(FaultyThread);
            t.Start();
            t.Join();

            try
            {
                t = new Thread(BadFaultyThread);
                t.Start();
            }
            catch(Exception ex)
            {
                Console.WriteLine("We won't get here!");
            }
        }
      
        static void BadFaultyThread()
        {
            Console.WriteLine("Starting a faulty thread...");
            Thread.Sleep(TimeSpan.FromSeconds(2));
            throw new Exception("Boom!");
        }

        static void FaultyThread()
        {
            try
            {
                Console.WriteLine("Starting a faulty thread...");
                Thread.Sleep(TimeSpan.FromSeconds(1));
                throw new Exception("Boom!");
            }
            catch(Exception ex)
            {
                Console.WriteLine("Exception handled:{0}", ex.Message);
            }
        }

    }
}

```