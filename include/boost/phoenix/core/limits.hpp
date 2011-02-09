/*=============================================================================
    Copyright (c) 2001-2007 Joel de Guzman

    Distributed under the Boost Software License, Version 1.0. (See accompanying 
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
#ifndef PHOENIX_CORE_LIMITS_HPP
#define PHOENIX_CORE_LIMITS_HPP

#include <boost/preprocessor/arithmetic/add.hpp>
#include <boost/preprocessor/inc.hpp>
#include <boost/preprocessor/dec.hpp>
#include <boost/preprocessor/stringize.hpp>
#include <boost/phoenix/support/preprocessor/round.hpp>

#if !defined(PHOENIX_LIMIT)
# define PHOENIX_LIMIT 10
#elif (PHOENIX_LIMIT < 5)
# error "PHOENIX_LIMIT is set too low"
#endif

#define PHOENIX_LIMIT_STR BOOST_PP_STRINGIZE(BOOST_PHOENIX_PP_ROUND_UP(PHOENIX_LIMIT))

#if !defined(PHOENIX_ARG_LIMIT)
# define PHOENIX_ARG_LIMIT BOOST_PHOENIX_PP_ROUND_UP(PHOENIX_LIMIT)
#elif (PHOENIX_ARG_LIMIT < 5)
# error "PHOENIX_ARG_LIMIT is set too low"
#elif PHOENIX_ARG_LIMIT != BOOST_PHOENIX_PP_ROUND_UP(PHOENIX_LIMIT) && !defined(PHOENIX_DONT_USE_PREPROCESSED_FILES)
# define PHOENIX_DONT_USE_PREPROCESSED_FILES
#endif

#if !defined(PHOENIX_ACTOR_LIMIT)
# define PHOENIX_ACTOR_LIMIT BOOST_PHOENIX_PP_ROUND_UP(PHOENIX_LIMIT)
#elif (PHOENIX_ACTOR_LIMIT > PHOENIX_ARG_LIMIT)
# error "PHOENIX_ACTOR_LIMIT > PHOENIX_ARG_LIMIT"
#elif (PHOENIX_ACTOR_LIMIT < 3)
# error "PHOENIX_ACTOR_LIMIT is set too low"
#elif PHOENIX_ACTOR_LIMIT != BOOST_PHOENIX_PP_ROUND_UP(PHOENIX_LIMIT) && !defined(PHOENIX_DONT_USE_PREPROCESSED_FILES)
# define PHOENIX_DONT_USE_PREPROCESSED_FILES
#endif

#if !defined(PHOENIX_PERFECT_FORWARD_LIMIT)
# define PHOENIX_PERFECT_FORWARD_LIMIT 3
#elif (PHOENIX_PERFECT_FORWARD_LIMIT > PHOENIX_ACTOR_LIMIT)
# error "PHOENIX_PERFECT_FORWARD_LIMIT > PHOENIX_ACTOR_LIMIT"
#elif (PHOENIX_PERFECT_FORWARD_LIMIT < 3)
# error "PHOENIX_PERFECT_FORWARD_LIMIT is set too low"
#elif PHOENIX_PERFECT_FORWARD_LIMIT != 3 && !defined(PHOENIX_DONT_USE_PREPROCESSED_FILES)
# define PHOENIX_DONT_USE_PREPROCESSED_FILES
#endif

#if !defined(PHOENIX_COMPOSITE_LIMIT)
# define PHOENIX_COMPOSITE_LIMIT BOOST_PHOENIX_PP_ROUND_UP(PHOENIX_LIMIT)
#elif (PHOENIX_COMPOSITE_LIMIT < 5)
# error "PHOENIX_COMPOSITE_LIMIT is set too low"
#elif PHOENIX_COMPOSITE_LIMIT != BOOST_PHOENIX_PP_ROUND_UP(PHOENIX_LIMIT) && !defined(PHOENIX_DONT_USE_PREPROCESSED_FILES)
# define PHOENIX_DONT_USE_PREPROCESSED_FILES
#endif

#if !defined(PHOENIX_MEMBER_LIMIT)
# define PHOENIX_MEMBER_LIMIT BOOST_PP_DEC(PHOENIX_COMPOSITE_LIMIT)
#elif (PHOENIX_MEMBER_LIMIT > PHOENIX_COMPOSITE_LIMIT)
# error "PHOENIX_MEMBER_LIMIT > PHOENIX_COMPOSITE_LIMIT"
#elif (PHOENIX_MEMBER_LIMIT < 3)
# error "PHOENIX_MEMBER_LIMIT is set too low"
#elif PHOENIX_MEMBER_LIMIT != BOOST_PHOENIX_PP_ROUND_UP(PHOENIX_LIMIT) && !defined(PHOENIX_DONT_USE_PREPROCESSED_FILES)
# define PHOENIX_DONT_USE_PREPROCESSED_FILES
#endif

#if !defined(PHOENIX_CATCH_LIMIT)
# define PHOENIX_CATCH_LIMIT PHOENIX_COMPOSITE_LIMIT
#elif (PHOENIX_CATCH_LIMIT < 1)
# error "PHOENIX_CATCH_LIMIT is set too low"
#elif PHOENIX_CATCH_LIMIT != BOOST_PHOENIX_PP_ROUND_UP(PHOENIX_LIMIT) && !defined(PHOENIX_DONT_USE_PREPROCESSED_FILES)
# define PHOENIX_DONT_USE_PREPROCESSED_FILES
#endif

#if !defined(PHOENIX_DYNAMIC_LIMIT)
# define PHOENIX_DYNAMIC_LIMIT BOOST_PHOENIX_PP_ROUND_UP(PHOENIX_LIMIT)
#elif (PHOENIX_DYNAMIC_LIMIT < 1)
# error "PHOENIX_DYNAMIC_LIMIT is set too low"
#elif PHOENIX_DYNAMIC_LIMIT != BOOST_PHOENIX_PP_ROUND_UP(PHOENIX_LIMIT) && !defined(PHOENIX_DONT_USE_PREPROCESSED_FILES)
# define PHOENIX_DONT_USE_PREPROCESSED_FILES
#endif

#if !defined(PHOENIX_LOCAL_LIMIT)
# define PHOENIX_LOCAL_LIMIT BOOST_PHOENIX_PP_ROUND_UP(PHOENIX_LIMIT)
#elif (PHOENIX_LOCAL_LIMIT < 3)
# error "PHOENIX_LOCAL_LIMIT is set too low"
#elif PHOENIX_LOCAL_LIMIT != BOOST_PHOENIX_PP_ROUND_UP(PHOENIX_LIMIT) && !defined(PHOENIX_DONT_USE_PREPROCESSED_FILES)
# define PHOENIX_DONT_USE_PREPROCESSED_FILES
#endif

#if !defined(BOOST_PROTO_MAX_ARITY)
#   define BOOST_PROTO_MAX_ARITY BOOST_PP_INC(PHOENIX_COMPOSITE_LIMIT)
#   if defined(BOOST_MPL_LIMIT_METAFUNCTION_ARITY)
#       undef BOOST_MPL_LIMIT_METAFUNCTION_ARITY 
#   endif
#   define BOOST_MPL_LIMIT_METAFUNCTION_ARITY BOOST_PP_INC(BOOST_PROTO_MAX_ARITY)
//#       define BOOST_MPL_CFG_NO_PREPROCESSED_HEADERS
//#   endif
#elif (BOOST_PROTO_MAX_ARITY < PHOENIX_COMPOSE_LIMIT)
#   error "BOOST_PROTO_MAX_ARITY < PHOENIX_COMPOSE_LIMIT"
#endif

#if !defined(BOOST_PROTO_MAX_LOGICAL_ARITY)
#   define BOOST_PROTO_MAX_LOGICAL_ARITY PHOENIX_COMPOSITE_LIMIT
#elif BOOST_PROTO_MAX_LOGICAL_ARITY < PHOENIX_COMPOSITE_LIMIT
#   error "BOOST_PROTO_MAX_LOGICAL_ARITY < PHOENIX_COMPOSITE_LIMIT"
#endif

// this include will set the limit for the proto expression arity
#include <boost/proto/proto_fwd.hpp>

#endif
