// implementation details, users never invoke these directly
namespace detail
{
    template <typename F, typename Tuple, bool Done, int Total, int... N>
    struct call_impl
    {
        static auto call(F f, Tuple && t) -> decltype (call_impl<F, Tuple, Total == 1 + sizeof...(N), Total, N..., sizeof...(N)>::call(f, std::forward<Tuple>(t)))
        {
            return call_impl<F, Tuple, Total == 1 + sizeof...(N), Total, N..., sizeof...(N)>::call(f, std::forward<Tuple>(t));
        }
    };

    template <typename F, typename Tuple, int Total, int... N>
    struct call_impl<F, Tuple, true, Total, N...>
    {
        static auto call(F f, Tuple && t) -> decltype (f(std::get<N>(std::forward<Tuple>(t))...))
        {
            return f(std::get<N>(std::forward<Tuple>(t))...);
        }
    };
}

// user invokes this

template <typename Tuple> using ttype = typename std::decay<Tuple>::type;

template <typename F, typename Tuple>
auto call(F f, Tuple && t) -> decltype(detail::call_impl<
        F,
        Tuple,
        0 == std::tuple_size<ttype<Tuple>>::value,
        std::tuple_size<ttype<Tuple>>::value>::call(f, std::forward<Tuple>(t)))
{
    return detail::call_impl<F, Tuple, 0 == std::tuple_size<ttype<Tuple>>::value, std::tuple_size<ttype<Tuple>>::value>::call(f, std::forward<Tuple>(t));
}