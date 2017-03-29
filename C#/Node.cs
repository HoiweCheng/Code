using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Example007
{
	public class Node<KT, VT>
	{
		public Node(KT key, VT value)
		{
			Key = key;
			Value = value;
			this.children = new NodeCollection<KT, VT>(this);
		}

		Tree<KT, VT> tree;
		public Tree<KT, VT> Tree
		{
			get
			{
				if (this.tree != null)
					return this.tree;
				else if (this.Parent != null)
					return this.Parent.Tree;
				else
					return null;
			}
			set
			{
				tree = value;
			}
		}

		public Node<KT, VT> Parent { get; internal set; }

		public KT Key { get; private set; }
		public VT Value { get; set; }

		NodeCollection<KT, VT> children;
		public NodeCollection<KT, VT> Children { get { return children; } }


	}

	public class NodeCollection<KT, VT> : IList<Node<KT, VT>>
	{
		Node<KT, VT> parent;
		List<Node<KT, VT>> list = new List<Node<KT, VT>>();

		public NodeCollection(Node<KT, VT> parentNode)
		{
			this.parent = parentNode;
		}

		public int IndexOf(Node<KT, VT> item)
		{
			return list.IndexOf(item);
		}

		public void Insert(int index, Node<KT, VT> item)
		{
			list.Insert(index, item);
			item.Parent = this.parent;
			Tree<KT, VT> tree = item.Tree;
			if (tree != null)
				tree.AddNodeIndex(item);
		}

		public void RemoveAt(int index)
		{
			list[index].Parent = null;
			Tree<KT, VT> tree = list[index].Tree;
			if (tree != null)
				tree.RemoveNodeIndex(list[index]);
			list.RemoveAt(index);

		}

		public Node<KT, VT> this[int index]
		{
			get
			{
				return list[index];
			}
			set
			{
				RemoveAt(index);
				Insert(index, value);
			}
		}

		public void Add(Node<KT, VT> item)
		{
			list.Add(item);
			item.Parent = this.parent;
			Tree<KT, VT> tree = item.Tree;
			if (tree != null)
				tree.AddNodeIndex(item);
		}

		public void Clear()
		{
			foreach (Node<KT, VT> n in list)
				n.Parent = null;
			this.Clear();
		}

		public bool Contains(Node<KT, VT> item)
		{
			return list.Contains(item);
		}

		public void CopyTo(Node<KT, VT>[] array, int arrayIndex)
		{
			int id = arrayIndex;
			foreach (Node<KT, VT> n in list)
				array[id++] = n;
		}

		public int Count
		{
			get { return list.Count; }
		}

		public bool IsReadOnly
		{
			get { return false; }
		}

		public bool Remove(Node<KT, VT> item)
		{
			item.Parent = null;
			Tree<KT, VT> tree = item.Tree;
			if (tree != null)
				tree.RemoveNodeIndex(item);
			return this.list.Remove(item);
		}

		public IEnumerator<Node<KT, VT>> GetEnumerator()
		{
			return list.GetEnumerator();
		}

		System.Collections.IEnumerator System.Collections.IEnumerable.GetEnumerator()
		{
			return list.GetEnumerator();
		}
	}

}
