using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Example007
{
	public class Tree<KT, VT>
	{
		SortedList<KT, Node<KT, VT>> list = new SortedList<KT, Node<KT, VT>>();

		public Node<KT, VT> CreateRoot(KT key, VT value)
		{
			Root = new Node<KT, VT>(key, value);
			Root.Tree = this;
			AddNodeIndex(Root);
			return Root;
		}

		internal void AddNodeIndex(Node<KT, VT> n)
		{
			list.Add(n.Key, n);
		}

		internal void RemoveNodeIndex(Node<KT, VT> n)
		{
			list.Remove(n.Key);
		}

		public Node<KT, VT> Root { get; private set; }

		public Node<KT, VT> this[KT key]
		{
			get
			{
				return list[key];
			}
		}
	}
}
