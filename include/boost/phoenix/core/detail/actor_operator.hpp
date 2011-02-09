
/*
#if !defined(PHOENIX_DONT_USE_PREPROCESSED_FILES)
#ifndef PHOENIX_CORE_DETAIL_ACTOR_OPERATOR_HPP
#define PHOENIX_CORE_DETAIL_ACTOR_OPERATOR_HPP

#include <boost/phoenix/support/iterate.hpp>

#include <boost/phoenix/core/detail/preprocessed/actor_operator.hpp>

#endif
#else*/

#if !PHOENIX_IS_ITERATING

#ifndef PHOENIX_CORE_DETAIL_ACTOR_OPERATOR_HPP
#define PHOENIX_CORE_DETAIL_ACTOR_OPERATOR_HPP

#include <boost/phoenix/support/iterate.hpp>

#if defined(__WAVE__) && defined(PHOENIX_CREATE_PREPROCESSED_FILES)
#pragma wave option(preserve: 2, line: 0, output: "preprocessed/actor_operator_" PHOENIX_LIMIT_STR ".hpp")
#endif
/*==============================================================================
    Copyright (c) 2005-2010 Joel de Guzman
    Copyright (c) 2010 Thomas Heller

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/

#if defined(__WAVE__) && defined(PHOENIX_CREATE_PREPROCESSED_FILES)
#pragma wave option(preserve: 1)
#endif

#define PHOENIX_ITERATION_PARAMS                                                \
        (3, (1, PHOENIX_ACTOR_LIMIT,                                            \
        <boost/phoenix/core/detail/actor_operator.hpp>))
#include PHOENIX_ITERATE()

#if defined(__WAVE__) && defined(PHOENIX_CREATE_PREPROCESSED_FILES)
#pragma wave option(output: null)
#endif

#endif

#else

        template <typename This, PHOENIX_typename_A>
        struct result<This(PHOENIX_A)>
            : result_of::actor<Expr, PHOENIX_A>
        {};

#if PHOENIX_ITERATION >= PHOENIX_PERFECT_FORWARD_LIMIT

        template <PHOENIX_typename_A>
        typename result_of::actor<Expr, PHOENIX_A_ref>::type
        operator()(PHOENIX_A_ref_a)
        {
            typedef
                BOOST_PP_CAT(vector, BOOST_PP_INC(PHOENIX_ITERATION))<
                    const actor<Expr> *, PHOENIX_A_ref
                >
                env_type;
            env_type env = {this, PHOENIX_a};
            
            return eval(*this, context(env, default_actions()));
        }

        template <PHOENIX_typename_A>
        typename result_of::actor<Expr, PHOENIX_A_ref>::type
        operator()(PHOENIX_A_ref_a) const
        {
            typedef
                BOOST_PP_CAT(vector, BOOST_PP_INC(PHOENIX_ITERATION))<
                    const actor<Expr> *, PHOENIX_A_ref
                >
                env_type;
            env_type env = {this, PHOENIX_a};
            
            return eval(*this, context(env, default_actions()));
        }

        template <PHOENIX_typename_A>
        typename result_of::actor<Expr, PHOENIX_A_const_ref>::type
        operator()(PHOENIX_A_const_ref_a)
        {
            typedef
                BOOST_PP_CAT(vector, BOOST_PP_INC(PHOENIX_ITERATION))<
                    const actor<Expr> *, PHOENIX_A_const_ref
                >
                env_type;
            env_type env = {this, PHOENIX_a};
            
            return eval(*this, context(env, default_actions()));
        }

        template <PHOENIX_typename_A>
        typename result_of::actor<Expr, PHOENIX_A_const_ref>::type
        operator()(PHOENIX_A_const_ref_a) const
        {
            typedef
                BOOST_PP_CAT(vector, BOOST_PP_INC(PHOENIX_ITERATION))<
                    const actor<Expr> *, PHOENIX_A_const_ref
                >
                env_type;
            env_type env = {this, PHOENIX_a};
            
            return eval(*this, context(env, default_actions()));
        }

#else

// We need to define operator() for all permutations of reference types.
// For PHOENIX_ITERATION <= PHOENIX_LIMIT_PREFECT_FORWARD
// 2^PHOENIX_ITERATION overloads are created
// For compile time reasons,
// if PHOENIX_ITERATION > PHOENIX_LIMIT_PERFECT_FORWARD
// only operator()(A const &...a) and operator()(A &...a) are generated
// this is all handled by the PP mumbo jumbo above
#define PHOENIX_ACTOR_OPERATOR(_, I, __)                                        \
        template <PHOENIX_typename_A>                                           \
        typename result_of::actor<Expr, PHOENIX_PERM_A(I)>::type                \
        operator()(PHOENIX_PERM_A_a(I)) const                                   \
        {                                                                       \
            typedef                                                             \
                BOOST_PP_CAT(vector, BOOST_PP_INC(PHOENIX_ITERATION))<          \
                    const actor<Expr> *, PHOENIX_PERM_A(I)                      \
                >                                                               \
                env_type;                                                       \
            env_type env = {this, PHOENIX_a};                                      \
                                                                                \
            return eval(*this, context(env, default_actions()));                \
        }                                                                       \
                                                                                \
        template <PHOENIX_typename_A>                                           \
        typename result_of::actor<Expr, PHOENIX_PERM_A(I)>::type                \
        operator()(PHOENIX_PERM_A_a(I))                                         \
        {                                                                       \
            typedef                                                             \
                BOOST_PP_CAT(vector, BOOST_PP_INC(PHOENIX_ITERATION))<          \
                    const actor<Expr> *, PHOENIX_PERM_A(I)                      \
                >                                                               \
                env_type;                                                       \
            env_type env = {this, PHOENIX_a};                                   \
                                                                                \
            return eval(*this, context(env, default_actions()));                \
        }                                                                       \
        /**/

        BOOST_PP_REPEAT( PHOENIX_PERM_SIZE, PHOENIX_ACTOR_OPERATOR, _)

#undef PHOENIX_ACTOR_OPERATOR

#endif

#endif

//#endif // PHOENIX_DONT_USE_PREPROCESSED_FILES
