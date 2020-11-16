using System;
using System.Collections.Generic;
using System.Threading;

using intPtr = System.Collections.Generic.List<int>;

namespace src
{
	class Program
	{
		public static intPtr CreateRandomArray(int n)
		{
			intPtr array = new intPtr();
			var rand = new Random();

			for (int i = 0; i < n; i++)
				array.Add(rand.Next(0, 500));

			return array;
		}

		public static Queue<intPtr> CreateQueue(int lenQueue, int countElem)
		{
			Queue<intPtr> queue = new Queue<intPtr>();

			for (int i = 0; i < lenQueue; i++)
				queue.Enqueue(CreateRandomArray(countElem));

			return queue;
		}

		public static int FindMax(intPtr array)
		{
			int max = array[0];

			foreach (var elem in array)
				if (elem > max)
					max = elem;

			return max;
		}

		public static int FindMin(intPtr array)
		{
			int min = array[0];

			foreach (var elem in array)
				if (elem < min)
					min = elem;

			return min;
		}

		// Кол-во элементов < (max - min) / 2.
		public static int FindCount(intPtr array, int num)
		{
			int count = 0;

			foreach (var elem in array)
				if (elem < num)
					count++;

			return count;
		}

		public static void PrintArray(intPtr array)
		{
			foreach (var elem in array)
				Console.Write("{0} ", elem);
			Console.WriteLine();
		}

		public static void PrintQueue(Queue<intPtr> queue)
		{
			if (queue.Count == 0)
			{
				Console.WriteLine("Queue is empty.\n");
				return;
			}

			foreach (var elem in queue)
				PrintArray(elem);
			Console.WriteLine();
		}


		static void Main(string[] args)
		{
			Console.WriteLine("Input array count: ");
			int count = Convert.ToInt32(Console.ReadLine());


			Console.WriteLine("Input array length: ");
			int n = Convert.ToInt32(Console.ReadLine());

			Queue<intPtr> queue = CreateQueue(count, n);

			MainTread(queue);
		}

		public static void Conveyor(object obj)
		{
			// Получили очереди.
			ThreadArgs queues = (ThreadArgs)obj;
			int max, min;
			intPtr array;

			lock (queues.firstQueue)
			{
				// Из первой очереди получили элемент.
				array = queues.firstQueue.Dequeue();
				// Нашли max.
				max = FindMax(array);
				Console.WriteLine("Max: {0}", max);
			}

			// Положили во вторую очередь.

			lock (queues.secondQueue)
			{
				queues.secondQueue.Enqueue(array);


				// Получили из второй очереди элемент.
				array = queues.secondQueue.Dequeue();
				// Нашли min.
				min = FindMin(array);
				Console.WriteLine("Min: {0}\n", min);
			}

			Console.WriteLine("Queues:\n");
			PrintQueue(queues.firstQueue);
			PrintQueue(queues.secondQueue);
			PrintQueue(queues.thirdQueue);
			Console.WriteLine("End");

		}

		public static void MainTread(Queue<intPtr> queue)
		{
			Console.WriteLine("\nBegin:\n");
			PrintQueue(queue);
			Console.WriteLine("Process:\n");

			ThreadArgs args = new ThreadArgs(queue);

			Thread myThread = new Thread(new ParameterizedThreadStart(Conveyor));
			myThread.Start(args);

			// myThread.Join();

			// Console.WriteLine("Queues:\n");
			// PrintQueue(args.firstQueue);
			// PrintQueue(args.secondQueue);
			// PrintQueue(args.thirdQueue);
			// Console.WriteLine("End");


			Thread myThread2 = new Thread(new ParameterizedThreadStart(Conveyor));
			myThread2.Start(args);
		}

	}

	public class ThreadArgs
	{
		// TODO: 
		// ThreadArgs - будет содержать 2 объекта:
		// Первый это очереди;
		// Второй это замеры времени.
		public Queue<intPtr> firstQueue = null;
		public Queue<intPtr> secondQueue = new Queue<intPtr>();
		public Queue<intPtr> thirdQueue = new Queue<intPtr>();

		public ThreadArgs(Queue<intPtr> queue) => firstQueue = queue;
	}
}

