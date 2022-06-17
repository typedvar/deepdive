#pragma once

#include <vector>

namespace dialga
{
	template <typename T>
	struct tree
	{
		T *_data = nullptr; // default constructible
		tree<T>* _left = nullptr;
		tree<T>* _right = nullptr;
		tree<T>* _parent = nullptr;

		tree<T>(T val)
			: _data(new T(val)) {}

		tree<T>() {}

		~tree<T>() {
			delete _left;
			delete _right;
			delete _data;
		}

		tree<T>(tree<T>&& source)
			: _data(source._data)
			, _left(source._left)
			, _right(source._right)
			, _parent(source._parent)
		{
			source._data = nullptr;
			source._left = nullptr;
			source._right = nullptr;
			source._parent = nullptr;
		}

		tree<T>* insert(T val)
		{
			tree<T>* ret = this;

			if (!_data)
			{
				_data = new T(val);
			}
			else
			{
				if (val < *_data)
				{
					if (_left)
					{
						ret = _left->insert(val);
					}
					else
					{
						_left = new tree<T>(val);
						_left->_parent = this;
						ret = _left;
					}
				}
				else if (*_data < val)
				{
					if (_right)
					{
						ret = _right->insert(val);
					}
					else
					{
						_right = new tree<T>(val);
						_right->_parent = this;
						ret = _right;
					}
				}
			}
			return ret;
		}

		tree<T>* left()
		{
			return _left;
		}

		tree<T>* right()
		{
			return _right;
		}

		void inOrder(std::vector<T>& out)
		{
			if (_left)
			{
				_left->inOrder(out);
			}
			else
			{
				out.push_back(std::numeric_limits<T>::min());
			}

			if (_data)
			{
				out.push_back(*_data);
			}

			if (_right)
			{
				_right->inOrder(out);
			}
			else
			{
				out.push_back(std::numeric_limits<T>::min());
			}
		}

		void preOrder(std::vector<T>& out)
		{
			if (_data)
			{
				out.push_back(*_data);
			}

			if (_left)
			{
				_left->preOrder(out);
			}
			else
			{
				out.push_back(std::numeric_limits<T>::min());
			}

			if (_right)
			{
				_right->preOrder(out);
			}
			else
			{
				out.push_back(std::numeric_limits<T>::min());
			}
		}

		void postOrder(std::vector<T>& out)
		{
			if (_left)
			{
				_left->postOrder(out);
			}
			else
			{
				out.push_back(std::numeric_limits<T>::min());
			}

			if (_right)
			{
				_right->postOrder(out);
			}
			else
			{
				out.push_back(std::numeric_limits<T>::min());
			}

			if (_data)
			{
				out.push_back(*_data);
			}
		}
	};
}

// eof

