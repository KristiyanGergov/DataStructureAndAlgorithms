using System;
using System.Collections;

namespace Task2
{
    public class StartUp
    {
        public class TrieNode
        {
            public TrieNode[] Arr { get; set; }
            public bool IsEnd { get; set; }

            public TrieNode()
            {
                this.Arr = new TrieNode[26];
            }
        }

        public class Trie
        {
            TrieNode root;

            public Trie()
            {
                root = new TrieNode();
            }

            public void Insert(string word)
            {
                TrieNode p = root;
                for (int i = 0; i < word.Length; i++)
                {
                    char c = word[i];
                    int index = c - 'a';
                    if (p.Arr[index] == null)
                    {
                        TrieNode temp = new TrieNode();
                        p.Arr[index] = temp;
                        p = temp;
                    }
                    else
                    {
                        p = p.Arr[index];
                    }
                }
                p.IsEnd = true;
            }

            public bool StartsWith(string prefix)
            {
                return SearchNode(prefix) != null;
            }

            TrieNode SearchNode(string s)
            {
                TrieNode p = root;
                for (int i = 0; i < s.Length; i++)
                {
                    char c = s[i];
                    int index = c - 'a';
                    if (p.Arr[index] != null)
                    {
                        p = p.Arr[index];
                    }
                    else
                    {
                        return null;
                    }
                }

                if (p == root)
                    return null;

                return p;
            }
        }

        public static void Main(string[] args)
        {
            Trie trie = new Trie();
            Hashtable map = new Hashtable();

            int len = int.Parse(Console.ReadLine());

            string[] strings = new string[len];
            for (int i = 0; i < len; i++)
            {
                strings[i] = Console.ReadLine();

                bool flag = true;
                for (int j = 1; j <= strings[i].Length; j++)
                {
                    string current = strings[i].Substring(0, j);

                    if (!trie.StartsWith(current))
                    {
                        Console.WriteLine(current);
                        flag = false;
                        break;
                    }
                }

                if (!map.ContainsKey(strings[i]))
                {
                    map.Add(strings[i], 1);
                    if (flag)
                    {
                        Console.WriteLine(strings[i]);
                    }
                }
                else
                {
                    map[strings[i]] = (int)map[strings[i]] + 1;
                    Console.WriteLine(strings[i] + " " + map[strings[i]]);
                }

                trie.Insert(strings[i]);
            }
        }
    }
}
