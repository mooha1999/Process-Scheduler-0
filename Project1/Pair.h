#pragma once
template<typename F = int, typename S = int>
class Pair
{
public:
	Pair(F f, S s) : first(f), second(s) {}
	const F first;
	const S second;
};
