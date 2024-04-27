using System;
using System.Collections.Generic;
using System.ComponentModel;
using BitcoinBlockchain.Data;
using BitcoinBlockchain.Parser;
using NBitcoin;

namespace t1
{
    internal class Program
    {
        static void Main(string[] args)
        {

            string path  = System.Environment.CurrentDirectory;

            Console.WriteLine(path);
            IBlockchainParser blockchainParser = new BlockchainParser(path);
            IEnumerable<ParserBlock> blocks = blockchainParser.ParseBlockchain();

            int len = 0;
            Tire tire = new Tire();
            //输出区块信息
            List<NewBlock> hashList = new List<NewBlock>();
            foreach(ParserBlock block in blocks){
                    len++;
                BlockHeader blockHeader = block.Header;

                string now = blockHeader.GetHash().ToString();
                string pre = blockHeader.HashPrevBlock.ToString();
                NewBlock newBlock = new NewBlock();
                newBlock.HashPrevBlock = pre;
                newBlock.Hash = now;
                newBlock.parserBlock = block;
                tire.Insert(newBlock, now);
                hashList.Add(newBlock);
            }
            int maxs = 0;
            foreach (NewBlock block in hashList)
            {
                tire.connect(block.HashPrevBlock, block.Hash);
            }
            List<List<NewBlock>> lists = new List<List<NewBlock>>();
            foreach (NewBlock block in hashList)
            {
                List<NewBlock> list = tire.getList(block.Hash);
                lists.Add(list);
                //Console.WriteLine(list.Count);
                if(list.Count > maxs)
                {
                    maxs = list.Count;
                }
            }
            Console.WriteLine("maxlen:"+ maxs);
            // 按照链长排序
            lists.Sort((a, b) => b.Count - a.Count);
            for(int i = 0; i < lists.Count; i++)
            {
                printList(lists[i]);

                save(lists[i], i, "C:\\Users\\DELLPC\\Desktop\\t\\save1\\");
            }
          //  利用字典树去重复

           tire = new Tire();

            List<List<NewBlock>> newlist = new List<List<NewBlock>>();

            foreach (List<NewBlock> list in lists)
            {
                //最后一个节点
                NewBlock lastBlock = list[list.Count - 1];
                if (tire.search(lastBlock.Hash) == null)
                {
                    newlist.Add(list);
                    for (int i = 0; i < list.Count; i++)
                    {
                        tire.Insert(list[i], list[i].Hash);
                    }
                }
            }

            for(int i = 0; i < newlist.Count; i++)
            {
                printList(newlist[i]);
                save(lists[i], i+200, "C:\\Users\\DELLPC\\Desktop\\t\\save2\\");
            }
        }



        static void save(List<NewBlock> list ,int i ,string  pre)
        {
            System.IO.Directory.CreateDirectory(pre);

            System.IO.StreamWriter file = new System.IO.StreamWriter(pre+ i.ToString()+".txt");
            foreach(NewBlock block in list)
            {
               file.WriteLine(  block.HashPrevBlock.ToString());
            }
            file.Close();
        }

        static void printList(List<NewBlock> list)
        {

               for( int i = 0; i < list.Count; i++)
               {
                 Console.WriteLine(list[i].Hash.ToString() + " " + list[i].HashPrevBlock.ToString() + " " + list[i].parserBlock.Header.BlockTime);
               }
                 Console.WriteLine("==================================");
        }

    }

    class NewBlock
    {
        public string Hash { get; set; }
        public string HashPrevBlock { get; set; }
        public  ParserBlock parserBlock { get; set; }


    }

    class TireNode
    {
        public Dictionary<char, TireNode> Children { get; set; }
        public bool IsEndOfWord { get; set; }
        public NewBlock newBlock { get; set; }
        public TireNode preNode { get; set; }
        public TireNode()
        {
            Children = new Dictionary<char, TireNode>();
        }
    }

    class Tire
    {
        TireNode root;
        public Tire()
        {
            root = new TireNode();
        }

        public void Insert(NewBlock newBlock, string hashCode)
        {
            TireNode current = root;
            foreach(char c in hashCode)
            {
                if(!current.Children.ContainsKey(c))
                {
                    current.Children[c] = new TireNode();
                }
                current = current.Children[c];
            }
            current.IsEndOfWord = true;
            current.newBlock = newBlock;
        }

        public TireNode search(string hashCode)
        {
            TireNode current = root;

            foreach(char c in hashCode)
            {
                if(!current.Children.ContainsKey(c))
                {
                    return null;
                }
                current = current.Children[c];
            }
            return  current;

        }

        public void connect(string pre, string now)
        {
            TireNode endTireNode =  search(pre);
            if(endTireNode == null)
            {
                return;
            }
            TireNode nowNode =  search(now);
            if(nowNode == null)
            {
                return;
            }
            endTireNode.preNode = nowNode;
        }

        public List<NewBlock> getList(string now)
        {
            Stack<NewBlock> parserBlocks = new Stack<NewBlock>();
            TireNode endTireNode = search(now);
            while(endTireNode != null)
            {
                parserBlocks.Push(endTireNode.newBlock);
                endTireNode = endTireNode.preNode;
            }

            List<NewBlock> list = new List<NewBlock>();
            while(parserBlocks.Count > 0)
            {
                list.Add(parserBlocks.Pop());
            }
            return list;
        }
    }
}

