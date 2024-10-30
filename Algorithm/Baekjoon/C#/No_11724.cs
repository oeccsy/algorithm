using System;
using System.Collections.Generic;

namespace Algorithm
{
    class Program
    {
        public class Node
        {
            public List<Node> adj = new List<Node>();
            public bool isVisit = false;
        }

        public static Node[] nodes = new Node[1005];
        public static int answer = 0;

        static void Main(string[] args)
        {
            string[] input = Console.ReadLine().Split(' ');
            int n = int.Parse(input[0]);
            int m = int.Parse(input[1]);

            for (int i = 1; i <= n; i++)
            {
                nodes[i] = new Node();
            }

            for (int i = 0; i < m; i++)
            {
                input = Console.ReadLine().Split(' ');
                int u = int.Parse(input[0]);
                int v = int.Parse(input[1]);

                nodes[u].adj.Add(nodes[v]);
                nodes[v].adj.Add(nodes[u]);
            }

            for (int i = 1; i <= n; i++)
            {
                if (nodes[i].isVisit) continue;

                answer++;
                Queue<Node> bfsQueue = new Queue<Node>();
                bfsQueue.Enqueue(nodes[i]);
                nodes[i].isVisit = true;

                while (bfsQueue.Count > 0)
                {
                    Node curNode = bfsQueue.Dequeue();

                    for (int j = 0; j < curNode.adj.Count; j++)
                    {
                        Node adjNode = curNode.adj[j];
                        if (adjNode.isVisit) continue;

                        adjNode.isVisit = true;
                        bfsQueue.Enqueue(adjNode);
                    }
                }
            }

            Console.WriteLine(answer);
        }
    }
}
