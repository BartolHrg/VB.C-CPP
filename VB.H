#ifndef VB_H
#define VB_H

// #pragma region basic
	#define __VB_C_FILE(...) __VA_ARGS__
	#define VB_C_FILE(...) __VB_C_FILE(__VA_ARGS__)

	#define __VB_C_ARGS(...) __VA_ARGS__
	
	#define __VB_C_FIRST(...) __VB_C_FIRST0(__VA_ARGS__)
	#define __VB_C_FIRST0(first, ...) __VB_C_ROB(first)
	
	// #pragma region remove optional bracket
		#define __VB_C_ARB(...) (__VA_ARGS__)
		#define __VB_C_RRB(...) __VB_C_RRB0(__VA_ARGS__)
		#define __VB_C_RRB0(...) __VB_C_ARGS __VA_ARGS__
	
		#define __VB_C_AOB(...) __VB_C_ROB(__VA_ARGS__)
		#define __VB_C_ROB(...) __VB_C_ROB0(__VB_C_OPT_B_REMOVER __VA_ARGS__)
		#define __VB_C_ROB0(...) __VB_C_ROB1(__VA_ARGS__)
		#define __VB_C_ROB1(...) __VB_C_ROB ## __VA_ARGS__
		#define __VB_C_OPT_B_REMOVER(...) __VB_C_OPT_B_M __VA_ARGS__
		#define __VB_C_ROB__VB_C_OPT_B_REMOVER
		#define __VB_C_ROB__VB_C_OPT_B_M
		
		#define __VB_C_AOB_IF_2(...) (__VB_C_ROB_IF_2(__VA_ARGS__))
		#define __VB_C_ROB_IF_2(...) __VB_C_ROB_IF_2_b __VA_ARGS__
		#define __VB_C_ROB_IF_2_b(...) __VB_C_ROB_IF_2_c(__VB_C_ROB_IF_2_o(__VB_C_ROB_IF_2_p __VA_ARGS__), __VA_ARGS__)
		#define __VB_C_ROB_IF_2_c(...) __VB_C_ROB_IF_2_d(__VA_ARGS__)
		#define __VB_C_ROB_IF_2_d(of, ...) __VB_C_ROB_IF_2_r##of (__VA_ARGS__)
		#define __VB_C_ROB_IF_2_o(...) __VB_C_FIRST(__VB_C_ROB_IF_2_q(__VA_ARGS__))
		#define __VB_C_ROB_IF_2_p(...) __VB_C_ROB_IF_2_s
		#define __VB_C_ROB_IF_2_q(...) __VB_C_ROB_IF_2_t##__VA_ARGS__
		#define __VB_C_ROB_IF_2_t__VB_C_ROB_IF_2_p __VB_C_ROB_IF_2_ttp,
		#define __VB_C_ROB_IF_2_t__VB_C_ROB_IF_2_s __VB_C_ROB_IF_2_tts,
		#define __VB_C_ROB_IF_2_r__VB_C_ROB_IF_2_ttp(...) (__VA_ARGS__)
		#define __VB_C_ROB_IF_2_r__VB_C_ROB_IF_2_tts(...)  __VA_ARGS__
	// #pragma endregion

	// #pragma region labels
		#define VB_C_LABEL(name, purpose) __VB_C_LABEL0(__VB_C_ROB(name), __VB_C_ROB(purpose))
		#define __VB_C_LABEL0(name, purpose) __VB_C_LABEL1(name, purpose)
		#define __VB_C_LABEL1(name, purpose) __VB_C_##name##_##purpose##_L
		
		#ifdef _MSC_VER
			#define __VB_C_LOCAL_LABELS(...)
		#else
			#define __VB_C_LOCAL_LABELS(...) __label__ __VA_ARGS__;
		#endif
	// #pragma endregion

	#define __VB_C_LB (
	#define __VB_C_RB )

	#define START ), __VB_C_START_M, (
	#define END ), __VB_C_END_M __VB_C_RB
// #pragma endregion
	
// #pragma region FORK
	// #pragma region IF
		/* 
		FORK IF cond THEN
			code
		[<ELSEIFs>]
		[ELSE
			code]
		END
		
		<ELSEIFs>
			ELSE IF cond THEN
				code
			[<ELSEIFs>]
		*/
		#define FORK __VB_C_FORK __VB_C_LB (
		#define IF ), __VB_C_IF_M __VB_C_RB __VB_C_IF __VB_C_LB (
		#define THEN ) __VB_C_RB __VB_C_THEN __VB_C_LB (
		#define ELSE ), __VB_C_ELSE_M __VB_C_RB __VB_C_ELSE __VB_C_LB (

		#define __VB_C_FORK(a, mark, ...) __VB_C_FORK##mark (a, __VA_ARGS__)
		
		#define __VB_C_FORK__VB_C_IF_M(...)
		#define __VB_C_IF(cond) if cond {{
		#define __VB_C_THEN(body, mark) __VB_C_THEN##mark (body)
		#define __VB_C_THEN__VB_C_ELSE_M(body)  __VB_C_ROB(body) }}
		#define __VB_C_THEN__VB_C_END_M(body)  __VB_C_ROB(body) }}
		#define __VB_C_ELSE(body, mark) __VB_C_ELSE##mark (body)
		#define __VB_C_ELSE__VB_C_IF_M(body) else
		#define __VB_C_ELSE__VB_C_END_M(body) else {{ __VB_C_ROB(body) }}
	// #pragma endregion
	// #pragma region CASE
		/*
		FORK x
		<CESEs>
		[DEFAULT
			code]
		END
		
		<CASEs>
			CASE a THEN
				code
			[<CASEs>]
		*/
		#define CASE ), __VB_C_CASE_M __VB_C_RB __VB_C_CASE __VB_C_LB (
		#define DEFAULT ), __VB_C_DEFAULT_M __VB_C_RB __VB_C_DEFAULT __VB_C_LB (
		
		#define __VB_C_FORK__VB_C_CASE_M(a, ...) switch a {
		#define __VB_C_CASE(a) case a: {
		#define __VB_C_THEN__VB_C_CASE_M(body) __VB_C_ROB(body) break; }
		#define __VB_C_THEN__VB_C_DEFAULT_M(body) __VB_C_ROB(body) break; }
		#define __VB_C_DEFAULT(body, mark) default: { __VB_C_ROB(body) } }
	// #pragma endregion
// #pragma endregion

// #pragma region loops
	#define PASS 
	#define SKIP( label) goto VB_C_LABEL(label, NEXT)
	#define BREAK(label) goto VB_C_LABEL(label, BREAK)

	// #pragma region LOOP
		/*
		LOOP
			code
		[<WHILEorSKIP_IFs>]
		[WHILE cond] // WHILE at the end doesn't need DO
		END
		<WHILEorSKIP_IFs>
		|	WHILE cond DO
				code
		|	SKIP_IF cond OTHERWISE
				code
		*/
		#define LOOP(label) __VB_C_LOOP __VB_C_LB label, (
		#define WHILE(label) __VB_C_RB __VB_C_WHILE __VB_C_LB label,
		#define DO __VB_C_RB __VB_C_ARGS __VB_C_LB
		#define SKIP_IF(label) __VB_C_SKIP_IF __VB_C_LB label, ( // if (
		#define OTHERWISE ) __VB_C_RB // ) continue;
		#define __VB_C_LOOP(label, body, ...) __VB_C_LOOP0(label, __VB_C_FOR_BODY_RESOLVE(__VB_C_START_M, body, __VA_ARGS__))
		#define __VB_C_LOOP0(...) __VB_C_LOOP1(__VA_ARGS__)
		#define __VB_C_LOOP1(label, body, didnt_break, ...) { __VB_C_LOCAL_LABELS(VB_C_LABEL(label, NEXT), VB_C_LABEL(label, AFTER), VB_C_LABEL(label, BREAK)) while (1) { VB_C_LABEL(label, NEXT):; __VB_C_ROB(body) } VB_C_LABEL(label, AFTER):; __VB_C_RRB(didnt_break) VB_C_LABEL(label, BREAK):; }
		#define __VB_C_SKIP_IF(label, ...) if ( (__VA_ARGS__)) goto VB_C_LABEL(label, NEXT );
		#define __VB_C_WHILE(  label, ...) if (!(__VA_ARGS__)) goto VB_C_LABEL(label, AFTER);
	// #pragma endregion

	// #pragma region FOR
	/*
	|	FOR code
			<CLASSIC>
		<BODY>
	|	FOR i IN [REVERSED] RANGE <DIM> <CLASSIC>
		<BODY>
	|	FOR el IN [REVERSED] arr AS ARRAY OF (<TYPE>) OF SIZE n [SLICED <DIM>] 
			<CLASSIC>
		<BODY>
	|	FOR el IN [REVERSED] arr AS ARRAY OF (<TYPE>) OF SIZE n [(SLICED <DIM2>)] // TODO: ADD OB
			<CLASSIC>
		<BODY>
	|	FOR el IN [REVERSED] arr AS MATRIX OF (<TYPE>) OF SIZE (m, n) [SLICED (<DIM2>, <DIM2>)] // TODO:"" ADD REVERSED
			<CLASSIC>
		<BODY>
	|	FOR el IN [REVERSED] arr AS CUBOID OF (<TYPE>) OF SIZE (m, n) [SLICED (<DIM2>, <DIM2>, <DIM2>)] 
			<CLASSIC>
		<BODY>	
	<CLASSIC>
		[PREP code]
		[COND cond]
		[STEP code]
	<BODY>
		START
			code
		END
	<DIM>
	|	n [BY delta]
	|	a TO b [BY delta]
	|	a UNTIL b [BY delta]
	<DIM2>
	|	<DIM>
	|	NORMAL
	*/
		#define FOR(label) __VB_C_FOR __VB_C_LB label, (VB_C_LABEL(label, NEXT), VB_C_LABEL(label, AFTER), VB_C_LABEL(label, BREAK)), VB_C_LABEL(label, NEXT):;, VB_C_LABEL(label, AFTER):;, VB_C_LABEL(label, BREAK):;, (

		#define IN ), __VB_C_IN_M, (
		
		#define MATRIX ), __VB_C_MATRIX_M, (
		#define CUBOID ), __VB_C_CUBOID_M, (
		#define SLICED ), __VB_C_SLICED_M, (

		#define NORMAL   ), __VB_C_NORMAL_M,   (
		#define REVERSED ), __VB_C_REVERSED_M, (
		#define RANGE ), __VB_C_RANGE_M, (
		#define FROM  ), __VB_C_FROM_M,  (
		#define UNTIL ), __VB_C_UNTIL_M, (
		#define TO    ), __VB_C_TO_M,    (
		#define BY    ), __VB_C_BY_M,    (
			
		#define PREP ), __VB_C_PREP_M, (
		#define COND ), __VB_C_COND_M, (
		#define STEP ), __VB_C_STEP_M, (

		#define DIDNT_BREAK ), __VB_C_DIDNT_BREAK_M, (

		#define __VB_C_FOR(label, labels, next_l, after_l, break_l, decl, mark, ...) __VB_C_FOR##mark(label, labels, next_l, after_l, break_l, decl, __VA_ARGS__)
		
		#define __VB_C_FOR__VB_C_PREP_M(  label, labels, next_l, after_l, break_l, decl, ...) __VB_C_FOR_CLASSIC(label, labels, next_l, after_l, break_l, decl, __VB_C_PREP_M,  __VA_ARGS__)
		#define __VB_C_FOR__VB_C_COND_M(  label, labels, next_l, after_l, break_l, decl, ...) __VB_C_FOR_CLASSIC(label, labels, next_l, after_l, break_l, decl, __VB_C_COND_M,  __VA_ARGS__)
		#define __VB_C_FOR__VB_C_STEP_M(  label, labels, next_l, after_l, break_l, decl, ...) __VB_C_FOR_CLASSIC(label, labels, next_l, after_l, break_l, decl, __VB_C_STEP_M,  __VA_ARGS__)
		#define __VB_C_FOR__VB_C_START_M( label, labels, next_l, after_l, break_l, decl, ...) __VB_C_FOR_CLASSIC(label, labels, next_l, after_l, break_l, decl, __VB_C_START_M, __VA_ARGS__)
		#define __VB_C_FOR__VB_C_AS_M(    label, labels, next_l, after_l, break_l, decl, ...) __VB_C_FOR_RANGE(  label, labels, next_l, after_l, break_l, decl, __VB_C_AS_M,    __VA_ARGS__)
		#define __VB_C_FOR__VB_C_IN_M(    label, labels, next_l, after_l, break_l, decl, ...) __VB_C_FOR_ARRAY(  label, labels, next_l, after_l, break_l, decl, __VB_C_IN_M,    __VA_ARGS__)
		
		// #pragma region classic
			#define __VB_C_FOR_CLASSIC(label, labels, next_l, after_l, break_l, decl, mark, ...) __VB_C_FOR_CLASSIC0(label, labels, next_l, after_l, break_l, decl, __VB_C_FOR_CLASSIC_RESOLVE(mark, __VA_ARGS__))
			#define __VB_C_FOR_CLASSIC0(...) __VB_C_FOR_CLASSIC1(__VA_ARGS__)
			#define __VB_C_FOR_CLASSIC1(label, labels, next_l, after_l, break_l, decl, prep, cond, step, ...) __VB_C_FOR_CLASSIC2(label, labels, next_l, after_l, break_l, decl,              prep, cond, step, __VB_C_FOR_BODY_RESOLVE(__VA_ARGS__))
			#define __VB_C_FOR_CLASSIC2(label, labels, next_l, after_l, break_l, decl, prep, cond, step, ...) __VB_C_FOR_FINAL(   label, labels, next_l, after_l, break_l, decl, (while (1) {{{), prep, cond, step, __VA_ARGS__)
			
			#define __VB_C_FOR_CLASSIC_RESOLVE(mark, x, ...) __VB_C_FOR_CLASSIC_RESOLVE0##mark(x, __VA_ARGS__)
			// #pragma region classic resolver
				#define __VB_C_FOR_CLASSIC_RESOLVE0__VB_C_PREP_M(prep, mark, ...) __VB_C_FOR_CLASSIC_RESOLVE1##mark        (prep,           __VA_ARGS__)
				#define __VB_C_FOR_CLASSIC_RESOLVE0__VB_C_COND_M(cond, mark, ...) __VB_C_FOR_CLASSIC_RESOLVE2##mark        ((),  cond,      __VA_ARGS__)
				#define __VB_C_FOR_CLASSIC_RESOLVE0__VB_C_STEP_M(step, mark, ...) __VB_C_FOR_CLASSIC_RESOLVE3##mark        ((),  (1), step, __VA_ARGS__)
				#define __VB_C_FOR_CLASSIC_RESOLVE0__VB_C_START_M(...)            __VB_C_FOR_CLASSIC_RESOLVE3__VB_C_START_M((),  (1), (),   __VA_ARGS__)

				#define __VB_C_FOR_CLASSIC_RESOLVE1__VB_C_COND_M( prep, cond, mark, ...) __VB_C_FOR_CLASSIC_RESOLVE2##mark        (prep, cond,      __VA_ARGS__)
				#define __VB_C_FOR_CLASSIC_RESOLVE1__VB_C_STEP_M( prep, step, mark, ...) __VB_C_FOR_CLASSIC_RESOLVE3##mark        (prep, (1), step, __VA_ARGS__)
				#define __VB_C_FOR_CLASSIC_RESOLVE1__VB_C_START_M(prep, ...)             __VB_C_FOR_CLASSIC_RESOLVE3__VB_C_START_M(prep, (1), (),   __VA_ARGS__)

				#define __VB_C_FOR_CLASSIC_RESOLVE2__VB_C_STEP_M( prep, cond, step, mark, ...) __VB_C_FOR_CLASSIC_RESOLVE3##mark        (prep, cond, step, __VA_ARGS__)
				#define __VB_C_FOR_CLASSIC_RESOLVE2__VB_C_START_M(prep, cond, ...)             __VB_C_FOR_CLASSIC_RESOLVE3__VB_C_START_M(prep, cond, (),   __VA_ARGS__)

				#define __VB_C_FOR_CLASSIC_RESOLVE3__VB_C_START_M(prep, cond, step, ...) prep, cond, step, __VB_C_START_M, __VA_ARGS__
			// #pragma endregion
		// #pragma endregion

		// #pragma region range
			#define __VB_C_FOR_RANGE(label, labels, next_l, after_l, break_l, var, as_m, type, in_m, ...) __VB_C_FOR_RANGE0(label, (__VB_C_RRB(labels), VB_C_LABEL(var, NEXT), VB_C_LABEL(var, AFTER), VB_C_LABEL(var, BREAK)), next_l VB_C_LABEL(var, NEXT):;, after_l VB_C_LABEL(var, AFTER):;, break_l VB_C_LABEL(var, BREAK):;, var, type, __VB_C_FOR_RANGE_RESOLVE(, __VB_C_i, __VA_ARGS__))
			#define __VB_C_FOR_RANGE0(...) __VB_C_FOR_RANGE1(__VA_ARGS__)
			#define __VB_C_FOR_RANGE1(label, labels, next_l, after_l, break_l, var, type, s, e, d, n, t, ...) __VB_C_FOR_RANGE2(label, labels, next_l, after_l, break_l, var, type, s, e, d, n, t, __VB_C_FOR_CLASSIC_RESOLVE(__VA_ARGS__))
			#define __VB_C_FOR_RANGE2(...) __VB_C_FOR_RANGE3(__VA_ARGS__)
			#define __VB_C_FOR_RANGE3(label, labels, next_l, after_l, break_l, var, type, s, e, d, n, t, prep, cond, step, ...) __VB_C_FOR_FINAL(label, labels, next_l, after_l, break_l, (__VB_C_DECL_RESOLVE(const __VB_C_start, type) = s; __VB_C_DECL_RESOLVE(const __VB_C_stop, type) = e; long const __VB_C_delta = d; long const __VB_C_n = n;), (for (long __VB_C_i = 0; __VB_C_i < __VB_C_n; ++__VB_C_i) {{{), (__VB_C_DECL_RESOLVE(var, type) = __VB_C_start + __VB_C_delta * t; __VB_C_RRB(prep)), cond, step, __VB_C_FOR_BODY_RESOLVE(__VA_ARGS__))
			
			/* n, I -> S, E, D, N, I, ... */
			#define __VB_C_FOR_RANGE_RESOLVE(...) __VB_C_FOR_RANGE_RESOLVE0(__VA_ARGS__)
			// #pragma region range resolver
				#define __VB_C_FOR_RANGE_RESOLVE0(                  n, I, _, mark, ...) __VB_C_FOR_RANGE_RESOLVE0##mark (n, I,                  __VA_ARGS__)
				#define __VB_C_FOR_RANGE_RESOLVE0__VB_C_REVERSED_M( n, I, _, mark, ...) __VB_C_FOR_RANGE_RESOLVE0##mark (n, (__VB_C_n - 1 - I), __VA_ARGS__)
				#define __VB_C_FOR_RANGE_RESOLVE0__VB_C_RANGE_M(    n, I, _,       ...) __VB_C_FOR_RANGE_RESOLVE1       (n, I,                  __VA_ARGS__)
				#define __VB_C_FOR_RANGE_RESOLVE0__VB_C_NORMAL_M(   n, I, _,       ...) (0), n, (1), n, I, __VA_ARGS__
				
				#define __VB_C_FOR_RANGE_RESOLVE1(               n, I, mark, ...) __VB_C_FOR_RANGE_RESOLVE1##mark (n, I,                 __VA_ARGS__)
				#define __VB_C_FOR_RANGE_RESOLVE1__VB_C_FROM_M(  n, I, a,    ...) __VB_C_FOR_RANGE_RESOLVE2       (n, I, a  ,            __VA_ARGS__)
				#define __VB_C_FOR_RANGE_RESOLVE1__VB_C_UNTIL_M( n, I, b,    ...) __VB_C_FOR_RANGE_RESOLVE3       (   I, (0), b     ,    __VA_ARGS__)
				#define __VB_C_FOR_RANGE_RESOLVE1__VB_C_TO_M(    n, I, b,    ...) __VB_C_FOR_RANGE_RESOLVE3       (   I, (0), (b+1)),    __VA_ARGS__)
				#define __VB_C_FOR_RANGE_RESOLVE1__VB_C_BY_M(    n, I, d,    ...) __VB_C_FOR_RANGE_RESOLVE4       (   I, (0), n     , d, __VA_ARGS__)
				
				#define __VB_C_FOR_RANGE_RESOLVE2(               n, I, a, mark, ...) __VB_C_FOR_RANGE_RESOLVE2##mark (n, I, a,           __VA_ARGS__)
				#define __VB_C_FOR_RANGE_RESOLVE2__VB_C_UNTIL_M( n, I, a, b,    ...) __VB_C_FOR_RANGE_RESOLVE3       (   I, a, b    ,    __VA_ARGS__)
				#define __VB_C_FOR_RANGE_RESOLVE2__VB_C_TO_M(    n, I, a, b,    ...) __VB_C_FOR_RANGE_RESOLVE3       (   I, a, (b+1),    __VA_ARGS__)
				#define __VB_C_FOR_RANGE_RESOLVE2__VB_C_BY_M(    n, I, a, d,    ...) __VB_C_FOR_RANGE_RESOLVE4       (   I, a, n    , d, __VA_ARGS__)
				// all endings
				#define __VB_C_FOR_RANGE_RESOLVE2__VB_C_PREP_M(     n, I, a, ...) a                          , n, (1), (__VB_C_stop - __VB_C_start), I, __VB_C_PREP_M    , __VA_ARGS__
				#define __VB_C_FOR_RANGE_RESOLVE2__VB_C_COND_M(     n, I, a, ...) a                          , n, (1), (__VB_C_stop - __VB_C_start), I, __VB_C_COND_M    , __VA_ARGS__
				#define __VB_C_FOR_RANGE_RESOLVE2__VB_C_STEP_M(     n, I, a, ...) a                          , n, (1), (__VB_C_stop - __VB_C_start), I, __VB_C_STEP_M    , __VA_ARGS__
				#define __VB_C_FOR_RANGE_RESOLVE2__VB_C_START_M(    n, I, a, ...) a                          , n, (1), (__VB_C_stop - __VB_C_start), I, __VB_C_START_M   , __VA_ARGS__
				#define __VB_C_FOR_RANGE_RESOLVE2__VB_C_REVERSED_M( n, I, a, ...) __VB_C_FIRST(__VB_C_ROB(a)), n, (1), (__VB_C_stop - __VB_C_start), I, __VB_C_REVERSED_M, __VA_ARGS__
				#define __VB_C_FOR_RANGE_RESOLVE2__VB_C_RANGE_M(    n, I, a, ...) __VB_C_FIRST(__VB_C_ROB(a)), n, (1), (__VB_C_stop - __VB_C_start), I, __VB_C_RANGE_M   , __VA_ARGS__
				#define __VB_C_FOR_RANGE_RESOLVE2__VB_C_NORMAL_M(   n, I, a, ...) __VB_C_FIRST(__VB_C_ROB(a)), n, (1), (__VB_C_stop - __VB_C_start), I, __VB_C_NORMAL_M  , __VA_ARGS__
	
				#define __VB_C_FOR_RANGE_RESOLVE3(            I, a, b, mark, ...) __VB_C_FOR_RANGE_RESOLVE3##mark (I, a, b,    __VA_ARGS__)
				#define __VB_C_FOR_RANGE_RESOLVE3__VB_C_BY_M( I, a, b, d,    ...) __VB_C_FOR_RANGE_RESOLVE4       (I, a, b, d, __VA_ARGS__)
				// all endings
				#define __VB_C_FOR_RANGE_RESOLVE3__VB_C_PREP_M(     I, a, b, ...) a, b                          , (1), (__VB_C_stop - __VB_C_start), I, __VB_C_PREP_M    , __VA_ARGS__
				#define __VB_C_FOR_RANGE_RESOLVE3__VB_C_COND_M(     I, a, b, ...) a, b                          , (1), (__VB_C_stop - __VB_C_start), I, __VB_C_COND_M    , __VA_ARGS__
				#define __VB_C_FOR_RANGE_RESOLVE3__VB_C_STEP_M(     I, a, b, ...) a, b                          , (1), (__VB_C_stop - __VB_C_start), I, __VB_C_STEP_M    , __VA_ARGS__
				#define __VB_C_FOR_RANGE_RESOLVE3__VB_C_START_M(    I, a, b, ...) a, b                          , (1), (__VB_C_stop - __VB_C_start), I, __VB_C_START_M   , __VA_ARGS__
				#define __VB_C_FOR_RANGE_RESOLVE3__VB_C_REVERSED_M( I, a, b, ...) a, __VB_C_FIRST(__VB_C_ROB(b)), (1), (__VB_C_stop - __VB_C_start), I, __VB_C_REVERSED_M, __VA_ARGS__
				#define __VB_C_FOR_RANGE_RESOLVE3__VB_C_RANGE_M(    I, a, b, ...) a, __VB_C_FIRST(__VB_C_ROB(b)), (1), (__VB_C_stop - __VB_C_start), I, __VB_C_RANGE_M   , __VA_ARGS__
				#define __VB_C_FOR_RANGE_RESOLVE3__VB_C_NORMAL_M(   I, a, b, ...) a, __VB_C_FIRST(__VB_C_ROB(b)), (1), (__VB_C_stop - __VB_C_start), I, __VB_C_NORMAL_M  , __VA_ARGS__
	
				#define __VB_C_FOR_RANGE_RESOLVE4( I, a, b, d, ...) a, b, __VB_C_FIRST(__VB_C_ROB(d)), (((__VB_C_delta == 0) ? (__VB_C_stop - __VB_C_start) : (__VB_C_stop - __VB_C_start + (__VB_C_delta > 0 ? __VB_C_delta-1 : __VB_C_delta + 1)) / __VB_C_delta)), I, __VA_ARGS__
			// #pragma endregion
		// #pragma endregion

		// #pragma region array
			#define __VB_C_FOR_ARRAY(label, labels, next_l, after_l, break_l, var, in_m, arr, as_m, _, mark, __, of_m, type, of_m2, ___, size_m, size, ...) __VB_C_FOR_ARRAY##mark (label, (__VB_C_RRB(labels), VB_C_LABEL(var, NEXT), VB_C_LABEL(var, AFTER), VB_C_LABEL(var, BREAK)), next_l VB_C_LABEL(var, NEXT):;, after_l VB_C_LABEL(var, AFTER):;, break_l VB_C_LABEL(var, BREAK):;, var, arr, type, __VB_C_ROB(__VB_C_ROB(size)), __VA_ARGS__)
		
			//                                       label, labels, next_l, after_l, break_l, var, arr, type, size, ...
			#define __VB_C_FOR_ARRAY__VB_C_ARRAY_M(  label, labels, next_l, after_l, break_l, var, arr, type, size, ...) __VB_C_FOR_ARRAY_A (label, labels, next_l, after_l, break_l, var, arr, type, size, __VA_ARGS__)
			#define __VB_C_FOR_ARRAY__VB_C_MATRIX_M( label, labels, next_l, after_l, break_l, var, arr, type, size, ...) __VB_C_FOR_ARRAY_M (label, labels, next_l, after_l, break_l, var, arr, type, size, __VA_ARGS__)
			#define __VB_C_FOR_ARRAY__VB_C_CUBOID_M( label, labels, next_l, after_l, break_l, var, arr, type, size, ...) __VB_C_FOR_ARRAY_C (label, labels, next_l, after_l, break_l, var, arr, type, size, __VA_ARGS__)
			
			// #pragma region ARRAY
				#define __VB_C_FOR_ARRAY_A(                  label, labels, next_l, after_l, break_l, var, arr, type, m, mark,    ...)                       __VB_C_FOR_ARRAY_A##mark(label, labels, next_l, after_l, break_l, var, arr, type, m, (m, __VB_C_i, , __VB_C_NORMAL_M, ), __VA_ARGS__)
				#define __VB_C_FOR_ARRAY_A__VB_C_SLICED_M(   label, labels, next_l, after_l, break_l, var, arr, type, m, slicing, _, by_m, slice, mark, ...) __VB_C_FOR_ARRAY_A##mark(label, labels, next_l, after_l, break_l, var, arr, type, m, (m, __VB_C_i, __VB_C_RRB(slice))  , __VA_ARGS__)
				#define __VB_C_FOR_ARRAY_A__VB_C_REVERSED_M( label, labels, next_l, after_l, break_l, var, arr, type, m, slicing, x,              mark, ...) __VB_C_FOR_ARRAY_A##mark(label, labels, next_l, after_l, break_l, var, arr, type, m, (__VB_C_RRB(slicing), __VB_C_REVERSED_M, x), __VA_ARGS__)
				#define __VB_C_FOR_ARRAY_A__VB_C_NORMAL_M(   label, labels, next_l, after_l, break_l, var, arr, type, m, slicing, x,              mark, ...) __VB_C_FOR_ARRAY_A##mark(label, labels, next_l, after_l, break_l, var, arr, type, m, (__VB_C_RRB(slicing), __VB_C_NORMAL_M  , x), __VA_ARGS__)
				#define __VB_C_FOR_ARRAY_A__VB_C_RANGE_M(    label, labels, next_l, after_l, break_l, var, arr, type, m, slicing, x,              mark, ...) __VB_C_FOR_ARRAY_A##mark(label, labels, next_l, after_l, break_l, var, arr, type, m, (__VB_C_RRB(slicing), __VB_C_RANGE_M   , x), __VA_ARGS__)
				#define __VB_C_FOR_ARRAY_A__VB_C_FROM_M(     label, labels, next_l, after_l, break_l, var, arr, type, m, slicing, x,              mark, ...) __VB_C_FOR_ARRAY_A##mark(label, labels, next_l, after_l, break_l, var, arr, type, m, (__VB_C_RRB(slicing), __VB_C_FROM_M    , x), __VA_ARGS__)
				#define __VB_C_FOR_ARRAY_A__VB_C_UNTIL_M(    label, labels, next_l, after_l, break_l, var, arr, type, m, slicing, x,              mark, ...) __VB_C_FOR_ARRAY_A##mark(label, labels, next_l, after_l, break_l, var, arr, type, m, (__VB_C_RRB(slicing), __VB_C_UNTIL_M   , x), __VA_ARGS__)
				#define __VB_C_FOR_ARRAY_A__VB_C_TO_M(       label, labels, next_l, after_l, break_l, var, arr, type, m, slicing, x,              mark, ...) __VB_C_FOR_ARRAY_A##mark(label, labels, next_l, after_l, break_l, var, arr, type, m, (__VB_C_RRB(slicing), __VB_C_TO_M      , x), __VA_ARGS__)
				#define __VB_C_FOR_ARRAY_A__VB_C_BY_M(       label, labels, next_l, after_l, break_l, var, arr, type, m, slicing, x,              mark, ...) __VB_C_FOR_ARRAY_A##mark(label, labels, next_l, after_l, break_l, var, arr, type, m, (__VB_C_RRB(slicing), __VB_C_BY_M      , x), __VA_ARGS__)
				#define __VB_C_FOR_ARRAY_A__VB_C_PREP_M(     label, labels, next_l, after_l, break_l, var, arr, type, m, slicing, ...)                       __VB_C_FOR_ARRAY_A0     (label, labels, next_l, after_l, break_l, var, arr, type, m, __VB_C_FOR_RANGE_RESOLVE(__VB_C_RRB(slicing), __VB_C_START_M), __VB_C_FOR_CLASSIC_RESOLVE(__VB_C_PREP_M , __VA_ARGS__))
				#define __VB_C_FOR_ARRAY_A__VB_C_COND_M(     label, labels, next_l, after_l, break_l, var, arr, type, m, slicing, ...)                       __VB_C_FOR_ARRAY_A0     (label, labels, next_l, after_l, break_l, var, arr, type, m, __VB_C_FOR_RANGE_RESOLVE(__VB_C_RRB(slicing), __VB_C_START_M), __VB_C_FOR_CLASSIC_RESOLVE(__VB_C_COND_M , __VA_ARGS__))
				#define __VB_C_FOR_ARRAY_A__VB_C_STEP_M(     label, labels, next_l, after_l, break_l, var, arr, type, m, slicing, ...)                       __VB_C_FOR_ARRAY_A0     (label, labels, next_l, after_l, break_l, var, arr, type, m, __VB_C_FOR_RANGE_RESOLVE(__VB_C_RRB(slicing), __VB_C_START_M), __VB_C_FOR_CLASSIC_RESOLVE(__VB_C_STEP_M , __VA_ARGS__))
				#define __VB_C_FOR_ARRAY_A__VB_C_START_M(    label, labels, next_l, after_l, break_l, var, arr, type, m, slicing, ...)                       __VB_C_FOR_ARRAY_A0     (label, labels, next_l, after_l, break_l, var, arr, type, m, __VB_C_FOR_RANGE_RESOLVE(__VB_C_RRB(slicing), __VB_C_START_M), __VB_C_FOR_CLASSIC_RESOLVE(__VB_C_START_M, __VA_ARGS__))
				
				#define __VB_C_FOR_ARRAY_A0(...)                                                                                                                  __VB_C_FOR_ARRAY_A1(__VA_ARGS__)
				#define __VB_C_FOR_ARRAY_A1(                 label, labels, next_l, after_l, break_l, var, arr, type, m, s, e, d, n, t, _, prep, cond, step, ...) __VB_C_FOR_ARRAY_A2(label, labels, next_l, after_l, break_l, var, arr, type, m, s, e, d, n, t, prep, cond, step, __VB_C_FOR_BODY_RESOLVE(__VA_ARGS__))
				#define __VB_C_FOR_ARRAY_A2(...)                                                                                                                  __VB_C_FOR_ARRAY_A3(__VA_ARGS__)
				#define __VB_C_FOR_ARRAY_A3(                 label, labels, next_l, after_l, break_l, var, arr, type, m, s, e, d, n, t,    prep, cond, step, body, didnt_break, ...) __VB_C_FOR_FINAL(label, labels, next_l, after_l, break_l, (long const __VB_C_start = s; long const __VB_C_stop = e; long const __VB_C_delta = d; long const __VB_C_n = n;), (for (long __VB_C_i = 0; __VB_C_i < __VB_C_n; ++__VB_C_i) { long i = __VB_C_start + __VB_C_delta * t; {{), (__VB_C_DECL_RESOLVE((*var), type) = &((__VB_C_DECL_RESOLVE((*), type))arr)[i]; __VB_C_RRB(prep)), cond, step, body, didnt_break, __VA_ARGS__)
			// #pragma endregion
			
			// #pragma region MATRIX
				#define __VB_C_FOR_ARRAY_M(                  label, labels, next_l, after_l, break_l, var, arr, type, m, n, mark,    ...)                       __VB_C_FOR_ARRAY_M##mark(label, labels, next_l, after_l, break_l, var, arr, type, m, n, (m, __VB_C_i, , __VB_C_NORMAL_M, (,), __VB_C_NORMAL_M, ), __VA_ARGS__)
				#define __VB_C_FOR_ARRAY_M__VB_C_SLICED_M(   label, labels, next_l, after_l, break_l, var, arr, type, m, n, slicing, _, by_m, slice, mark, ...) __VB_C_FOR_ARRAY_M##mark(label, labels, next_l, after_l, break_l, var, arr, type, m, n, (m, __VB_C_i, __VB_C_RRB(slice))  , __VA_ARGS__)
				#define __VB_C_FOR_ARRAY_M__VB_C_PREP_M(     label, labels, next_l, after_l, break_l, var, arr, type, m, n, slicing, ...)                       __VB_C_FOR_ARRAY_M0     (label, labels, next_l, after_l, break_l, var, arr, type, m, n, __VB_C_FOR_RANGE_RESOLVE(__VB_C_RRB(slicing), __VB_C_START_M), __VB_C_FOR_CLASSIC_RESOLVE(__VB_C_PREP_M , __VA_ARGS__))
				#define __VB_C_FOR_ARRAY_M__VB_C_COND_M(     label, labels, next_l, after_l, break_l, var, arr, type, m, n, slicing, ...)                       __VB_C_FOR_ARRAY_M0     (label, labels, next_l, after_l, break_l, var, arr, type, m, n, __VB_C_FOR_RANGE_RESOLVE(__VB_C_RRB(slicing), __VB_C_START_M), __VB_C_FOR_CLASSIC_RESOLVE(__VB_C_COND_M , __VA_ARGS__))
				#define __VB_C_FOR_ARRAY_M__VB_C_STEP_M(     label, labels, next_l, after_l, break_l, var, arr, type, m, n, slicing, ...)                       __VB_C_FOR_ARRAY_M0     (label, labels, next_l, after_l, break_l, var, arr, type, m, n, __VB_C_FOR_RANGE_RESOLVE(__VB_C_RRB(slicing), __VB_C_START_M), __VB_C_FOR_CLASSIC_RESOLVE(__VB_C_STEP_M , __VA_ARGS__))
				#define __VB_C_FOR_ARRAY_M__VB_C_START_M(    label, labels, next_l, after_l, break_l, var, arr, type, m, n, slicing, ...)                       __VB_C_FOR_ARRAY_M0     (label, labels, next_l, after_l, break_l, var, arr, type, m, n, __VB_C_FOR_RANGE_RESOLVE(__VB_C_RRB(slicing), __VB_C_START_M), __VB_C_FOR_CLASSIC_RESOLVE(__VB_C_START_M, __VA_ARGS__))
				
				#define __VB_C_FOR_ARRAY_M0(...)                                                                                                                                              __VB_C_FOR_ARRAY_M1(__VA_ARGS__)
				#define __VB_C_FOR_ARRAY_M1(                 label, labels, next_l, after_l, break_l, var, arr, type, m, n, si, ei, di, ni, ti, ...)                                          __VB_C_FOR_ARRAY_M2(label, labels, next_l, after_l, break_l, var, arr, type, m, n, si, ei, di, ni, ti, __VB_C_FOR_RANGE_RESOLVE(n, __VB_C_j, , __VA_ARGS__)) // prep, cond, step, __VB_C_FOR_BODY_RESOLVE(__VA_ARGS__))
				#define __VB_C_FOR_ARRAY_M2(...)                                                                                                                                              __VB_C_FOR_ARRAY_M3(__VA_ARGS__)
				#define __VB_C_FOR_ARRAY_M3(                 label, labels, next_l, after_l, break_l, var, arr, type, m, n, si, ei, di, ni, ti, sj, ej, dj, nj, tj, _, prep, cond, step, ...) __VB_C_FOR_ARRAY_M4(label, labels, next_l, after_l, break_l, var, arr, type, m, n, si, ei, di, ni, ti, sj, ej, dj, nj, tj, prep, cond, step, __VB_C_FOR_BODY_RESOLVE(__VA_ARGS__))
				#define __VB_C_FOR_ARRAY_M4(...)                                                                                                                                              __VB_C_FOR_ARRAY_M5(__VA_ARGS__)
				#define __VB_C_FOR_ARRAY_M5(                 label, labels, next_l, after_l, break_l, var, arr, type, m, n, si, ei, di, ni, ti, sj, ej, dj, nj, tj,    prep, cond, step, body, didnt_break, ...) __VB_C_FOR_FINAL(label, labels, next_l, after_l, break_l, (long const __VB_C_start = si; long const __VB_C_stop = ei; long const __VB_C_delta = di; long const __VB_C_n = ni;), (for (long __VB_C_i = 0; __VB_C_i < __VB_C_n; ++__VB_C_i) { long const i = __VB_C_start + __VB_C_delta * ti; long const __VB_C_start = sj; long const __VB_C_stop = ej; long const __VB_C_delta = dj; long const __VB_C_n = nj; for (long __VB_C_j = 0; __VB_C_j < __VB_C_n; ++__VB_C_j) { long const j = __VB_C_start + __VB_C_delta + tj; {), (__VB_C_DECL_RESOLVE((*var), type) = &CAST(arr AS POINTER TO ARRAY OF __VB_C_ROB_IF_2(type) OF SIZE [n])[i][j]; __VB_C_RRB(prep)), cond, step, body, didnt_break, __VA_ARGS__)
			// #pragma endregion
			
			// #pragma region CUBOID
				#define __VB_C_FOR_ARRAY_C(                  label, labels, next_l, after_l, break_l, var, arr, type, m, n, o, mark,    ...)                       __VB_C_FOR_ARRAY_C##mark(label, labels, next_l, after_l, break_l, var, arr, type, m, n, o, (m, __VB_C_i, , __VB_C_NORMAL_M, (,), __VB_C_NORMAL_M, (,), __VB_C_NORMAL_M, ), __VA_ARGS__)
				#define __VB_C_FOR_ARRAY_C__VB_C_SLICED_M(   label, labels, next_l, after_l, break_l, var, arr, type, m, n, o, slicing, _, by_m, slice, mark, ...) __VB_C_FOR_ARRAY_C##mark(label, labels, next_l, after_l, break_l, var, arr, type, m, n, o, (m, __VB_C_i, __VB_C_RRB(slice))  , __VA_ARGS__)
				#define __VB_C_FOR_ARRAY_C__VB_C_PREP_M(     label, labels, next_l, after_l, break_l, var, arr, type, m, n, o, slicing, ...)                       __VB_C_FOR_ARRAY_C0     (label, labels, next_l, after_l, break_l, var, arr, type, m, n, o, __VB_C_FOR_RANGE_RESOLVE(__VB_C_RRB(slicing), __VB_C_START_M), __VB_C_FOR_CLASSIC_RESOLVE(__VB_C_PREP_M , __VA_ARGS__))
				#define __VB_C_FOR_ARRAY_C__VB_C_COND_M(     label, labels, next_l, after_l, break_l, var, arr, type, m, n, o, slicing, ...)                       __VB_C_FOR_ARRAY_C0     (label, labels, next_l, after_l, break_l, var, arr, type, m, n, o, __VB_C_FOR_RANGE_RESOLVE(__VB_C_RRB(slicing), __VB_C_START_M), __VB_C_FOR_CLASSIC_RESOLVE(__VB_C_COND_M , __VA_ARGS__))
				#define __VB_C_FOR_ARRAY_C__VB_C_STEP_M(     label, labels, next_l, after_l, break_l, var, arr, type, m, n, o, slicing, ...)                       __VB_C_FOR_ARRAY_C0     (label, labels, next_l, after_l, break_l, var, arr, type, m, n, o, __VB_C_FOR_RANGE_RESOLVE(__VB_C_RRB(slicing), __VB_C_START_M), __VB_C_FOR_CLASSIC_RESOLVE(__VB_C_STEP_M , __VA_ARGS__))
				#define __VB_C_FOR_ARRAY_C__VB_C_START_M(    label, labels, next_l, after_l, break_l, var, arr, type, m, n, o, slicing, ...)                       __VB_C_FOR_ARRAY_C0     (label, labels, next_l, after_l, break_l, var, arr, type, m, n, o, __VB_C_FOR_RANGE_RESOLVE(__VB_C_RRB(slicing), __VB_C_START_M), __VB_C_FOR_CLASSIC_RESOLVE(__VB_C_START_M, __VA_ARGS__))
				
				#define __VB_C_FOR_ARRAY_C0(...)                                                                                                                                                                     __VB_C_FOR_ARRAY_C1(__VA_ARGS__)
				#define __VB_C_FOR_ARRAY_C1(                 label, labels, next_l, after_l, break_l, var, arr, type, m, n, o, si, ei, di, ni, ti, ...)                                                              __VB_C_FOR_ARRAY_C2(label, labels, next_l, after_l, break_l, var, arr, type, m, n, o, si, ei, di, ni, ti, __VB_C_FOR_RANGE_RESOLVE(n, __VB_C_j, , __VA_ARGS__)) // prep, cond, step, __VB_C_FOR_BODY_RESOLVE(__VA_ARGS__))
				#define __VB_C_FOR_ARRAY_C2(...)                                                                                                                                                                     __VB_C_FOR_ARRAY_C3(__VA_ARGS__)
				#define __VB_C_FOR_ARRAY_C3(                 label, labels, next_l, after_l, break_l, var, arr, type, m, n, o, si, ei, di, ni, ti, sj, ej, dj, nj, tj, ...)                                          __VB_C_FOR_ARRAY_C4(label, labels, next_l, after_l, break_l, var, arr, type, m, n, o, si, ei, di, ni, ti, sj, ej, dj, nj, tj, __VB_C_FOR_RANGE_RESOLVE(o, __VB_C_k, , __VA_ARGS__))
				#define __VB_C_FOR_ARRAY_C4(...)                                                                                                                                                                     __VB_C_FOR_ARRAY_C5(__VA_ARGS__)
				#define __VB_C_FOR_ARRAY_C5(                 label, labels, next_l, after_l, break_l, var, arr, type, m, n, o, si, ei, di, ni, ti, sj, ej, dj, nj, tj, sk, ek, dk, nk, tk, _, prep, cond, step, ...) __VB_C_FOR_ARRAY_C6(label, labels, next_l, after_l, break_l, var, arr, type, m, n, o, si, ei, di, ni, ti, sj, ej, dj, nj, tj, sk, ek, dk, nk, tk, prep, cond, step, __VB_C_FOR_BODY_RESOLVE(__VA_ARGS__))
				#define __VB_C_FOR_ARRAY_C6(...)                                                                                                                                                                     __VB_C_FOR_ARRAY_C7(__VA_ARGS__)
				#define __VB_C_FOR_ARRAY_C7(                 label, labels, next_l, after_l, break_l, var, arr, type, m, n, o, si, ei, di, ni, ti, sj, ej, dj, nj, tj, sk, ek, dk, nk, tk,    prep, cond, step, body, didnt_break, ...) __VB_C_FOR_FINAL(label, labels, next_l, after_l, break_l, (long const __VB_C_start = si; long const __VB_C_stop = ei; long const __VB_C_delta = di; long const __VB_C_n = ni;), (for (long __VB_C_i = 0; __VB_C_i < __VB_C_n; ++__VB_C_i) { long const i = __VB_C_start + __VB_C_delta * ti; long const __VB_C_start = sj; long const __VB_C_stop = ej; long const __VB_C_delta = dj; long const __VB_C_n = nj; for (long __VB_C_j = 0; __VB_C_j < __VB_C_n; ++__VB_C_j) { long const j = __VB_C_start + __VB_C_delta + tj; long const __VB_C_start = sk; long const __VB_C_stop = ek; long const __VB_C_delta = dk; long const __VB_C_n = nk; for (long __VB_C_k = 0; __VB_C_k < __VB_C_n; ++__VB_C_k) { long const k = __VB_C_start + __VB_C_delta + tk; ), (__VB_C_DECL_RESOLVE((*var), type) = &CAST(arr AS POINTER TO ARRAY OF __VB_C_ROB_IF_2(type) OF SIZE [n][o])[i][j][k]; __VB_C_RRB(prep)), cond, step, body, didnt_break, __VA_ARGS__)
			// #pragma endregion
		// #pragma endregion

		#define __VB_C_FOR_BODY_RESOLVE(...) __VB_C_FOR_BODY_RESOLVE0(__VA_ARGS__)
		// #pragma region for body resolver
			#define __VB_C_FOR_BODY_RESOLVE0(start_m, body, mark, ...) __VB_C_FOR_BODY_RESOLVE0##mark (body, __VA_ARGS__)
			#define __VB_C_FOR_BODY_RESOLVE0__VB_C_DIDNT_BREAK_M(body, didnt_break, ...) body, didnt_break, __VA_ARGS__
			#define __VB_C_FOR_BODY_RESOLVE0__VB_C_END_M(        body,              ...) body, (),          __VA_ARGS__
		// #pragma endregion
		
		#define __VB_C_FOR_FINAL(...) __VB_C_FOR_FINAL0(__VA_ARGS__)
		// #define __VB_C_FOR_FINAL0(label, labels, next_l, after_l, break_l, decl, loop, prep, cond, step, body, didnt_break, ...) { __VB_C_LOCAL_LABELS(__VB_C_RRB(labels)); __VB_C_RRB(decl) /*char __VB_C_broke = 0, __VB_C_first = 1*/; __VB_C_RRB(loop) { if (!__VB_C_first) {__VB_C_RRB(step)} __VB_C_first=0; __VB_C_RRB(prep) if (!cond) {BREAK;} __VB_C_RRB(body) } }} if (!__VB_C_broke) { __VB_C_RRB(didnt_break) } }
		#define __VB_C_FOR_FINAL0(label, labels, next_l, after_l, break_l, decl, loop, prep, cond, step, body, didnt_break, ...) { __VB_C_LOCAL_LABELS(__VB_C_RRB(labels)); __VB_C_RRB(decl) __VB_C_RRB(loop)  __VB_C_RRB(prep) if (!cond) {goto VB_C_LABEL(label, AFTER);} __VB_C_RRB(body) next_l __VB_C_RRB(step) } }} after_l __VB_C_RRB(didnt_break) break_l }
	// #pragma endregion
// #pragma endregion


#define SCOPE __VB_C_SCOPE __VB_C_LB (
#define __VB_C_SCOPE(body, _) { __VB_C_ROB(body) }

// #pragma region types
	// #pragma region variable declaration
		/*	DECL var AS <TYPE> END
		<TYPE> 
		|	type
		|	POINTER TO <TYPE>
		|	ARRAY OF (<TYPE>) OF SIZE <SIZE>
		|	FUNC OF (args) RETURNING <TYPE>
		<SIZE>
		|	[]
		|	[n]
		|	<SIZE><SIZE>
		*/
		#define DECL __VB_C_DECL __VB_C_LB (
		#define AS ), __VB_C_AS_M, (
		#define RETURNING ), __VB_C_RETURNING_M, (
		#define FUNC ), __VB_C_FUNC_M, (
		#define SIZE ), __VB_C_SIZE_M, (
		#define POINTER ), __VB_C_POINTER_M, (
		#define __VB_C_DECL(var, as_m, ...) __VB_C_FIRST(__VB_C_TYPE_RESOLVE(var, __VA_ARGS__))
		#define __VB_C_DECL_RESOLVE(var, type) __VB_C_DECL_RESOLVE0(var, __VB_C_RRB(type))
		#define __VB_C_DECL_RESOLVE0(var, ...) __VB_C_FIRST(__VB_C_TYPE_RESOLVE(var, __VA_ARGS__, __VB_C_END_M))
		
		#define DEFINE_LATER extern
		#define GLOBAL_PRIVATE static
		#define LOCAL_DEFINE_ONCE static
		
		#define ARRAY  ), __VB_C_ARRAY_M , (
		#define ZERO_ARRAY {0}
		#define REST_ALL_ZEROS

		#define AS_FUNC 

		#define __VB_C_TYPE_RESOLVE(...) __VB_C_TYPE_RESOLVE_(__VA_ARGS__)
		#define __VB_C_TYPE_RESOLVE_(name, x, mark, ...) __VB_C_TYPE_RESOLVE0##mark (name, x, __VA_ARGS__)
		// #pragma region type resolve I need recursion
			#define __VB_C_TYPE_RESOLVE0(...) __VB_C_TYPE_RESOLVE0_(__VA_ARGS__)
			#define __VB_C_TYPE_RESOLVE0_(name, x, mark, ...) __VB_C_TYPE_RESOLVE0##mark(name, x, __VA_ARGS__)
			#define __VB_C_TYPE_RESOLVE0__VB_C_START_M(   name, type,                                           ... ) ( __VB_C_ROB(type) name ), __VB_C_START_M, __VA_ARGS__
			#define __VB_C_TYPE_RESOLVE0__VB_C_END_M(     name, type,                                           ... ) ( __VB_C_ROB(type) name ), __VB_C_END_M,   __VA_ARGS__
			#define __VB_C_TYPE_RESOLVE0__VB_C_POINTER_M( name, _,     q, to_m,                                 ... ) __VB_C_TYPE_RESOLVE1((*__VB_C_RRB(q) name),    __VA_ARGS__)
			#define __VB_C_TYPE_RESOLVE0__VB_C_FUNC_M(    name, _,     q, of_m, args, ret_m,                    ... ) __VB_C_TYPE_RESOLVE1((*__VB_C_RRB(q) name) __VB_C_ROB(args), __VA_ARGS__)
			#define __VB_C_TYPE_RESOLVE0__VB_C_ARRAY_M(   name, _,    __, of_m, type, of_m2, ___, size_m, size, ... ) (__VB_C_FIRST(__VB_C_TYPE_RESOLVE1((name __VB_C_ROB(size)), __VB_C_ROB_IF_2(type), __VB_C_END_M))), __VA_ARGS__

			// #define __VB_C_TYPE_RESOLVE1(name, x, mark, ...) __VB_C_TYPE_RESOLVE1##mark(name, x, __VA_ARGS__)
			#define __VB_C_TYPE_RESOLVE1(...) __VB_C_TYPE_RESOLVE1_(__VA_ARGS__)
			#define __VB_C_TYPE_RESOLVE1_(name, x, mark, ...) __VB_C_TYPE_RESOLVE1##mark(name, x, __VA_ARGS__)
			#define __VB_C_TYPE_RESOLVE1__VB_C_START_M(   name, type,                                           ... ) ( __VB_C_ROB(type) name ), __VB_C_START_M, __VA_ARGS__
			#define __VB_C_TYPE_RESOLVE1__VB_C_END_M(     name, type,                                           ... ) ( __VB_C_ROB(type) name ), __VB_C_END_M,   __VA_ARGS__
			#define __VB_C_TYPE_RESOLVE1__VB_C_POINTER_M( name, _,     q, to_m,                                 ... ) __VB_C_TYPE_RESOLVE2((*__VB_C_RRB(q) name),    __VA_ARGS__)
			#define __VB_C_TYPE_RESOLVE1__VB_C_FUNC_M(    name, _,     q, of_m, args, ret_m,                    ... ) __VB_C_TYPE_RESOLVE2((*__VB_C_RRB(q) name) __VB_C_ROB(args), __VA_ARGS__)
			#define __VB_C_TYPE_RESOLVE1__VB_C_ARRAY_M(   name, _,    __, of_m, type, of_m2, ___, size_m, size, ... ) (__VB_C_FIRST(__VB_C_TYPE_RESOLVE2((name __VB_C_ROB(size)), __VB_C_ROB_IF_2(type), __VB_C_END_M))), __VA_ARGS__

			#define __VB_C_TYPE_RESOLVE2(...) __VB_C_TYPE_RESOLVE2_(__VA_ARGS__)
			#define __VB_C_TYPE_RESOLVE2_(name, x, mark, ...) __VB_C_TYPE_RESOLVE2##mark(name, x, __VA_ARGS__)
			#define __VB_C_TYPE_RESOLVE2__VB_C_START_M(   name, type,                                           ... ) ( __VB_C_ROB(type) name ), __VB_C_START_M, __VA_ARGS__
			#define __VB_C_TYPE_RESOLVE2__VB_C_END_M(     name, type,                                           ... ) ( __VB_C_ROB(type) name ), __VB_C_END_M,   __VA_ARGS__
			#define __VB_C_TYPE_RESOLVE2__VB_C_POINTER_M( name, _,     q, to_m,                                 ... ) __VB_C_TYPE_RESOLVE3((*__VB_C_RRB(q) name),    __VA_ARGS__)
			#define __VB_C_TYPE_RESOLVE2__VB_C_FUNC_M(    name, _,     q, of_m, args, ret_m,                    ... ) __VB_C_TYPE_RESOLVE3((*__VB_C_RRB(q) name) __VB_C_ROB(args), __VA_ARGS__)
			#define __VB_C_TYPE_RESOLVE2__VB_C_ARRAY_M(   name, _,    __, of_m, type, of_m2, ___, size_m, size, ... ) (__VB_C_FIRST(__VB_C_TYPE_RESOLVE3((name __VB_C_ROB(size)), __VB_C_ROB_IF_2(type), __VB_C_END_M))), __VA_ARGS__

			#define __VB_C_TYPE_RESOLVE3(...) __VB_C_TYPE_RESOLVE3_(__VA_ARGS__)
			#define __VB_C_TYPE_RESOLVE3_(name, x, mark, ...) __VB_C_TYPE_RESOLVE3##mark(name, x, __VA_ARGS__)
			#define __VB_C_TYPE_RESOLVE3__VB_C_START_M(   name, type,                                           ... ) ( __VB_C_ROB(type) name ), __VB_C_START_M, __VA_ARGS__
			#define __VB_C_TYPE_RESOLVE3__VB_C_END_M(     name, type,                                           ... ) ( __VB_C_ROB(type) name ), __VB_C_END_M,   __VA_ARGS__
			#define __VB_C_TYPE_RESOLVE3__VB_C_POINTER_M( name, _,     q, to_m,                                 ... ) __VB_C_TYPE_RESOLVE4((*__VB_C_RRB(q) name),    __VA_ARGS__)
			#define __VB_C_TYPE_RESOLVE3__VB_C_FUNC_M(    name, _,     q, of_m, args, ret_m,                    ... ) __VB_C_TYPE_RESOLVE4((*__VB_C_RRB(q) name) __VB_C_ROB(args), __VA_ARGS__)
			#define __VB_C_TYPE_RESOLVE3__VB_C_ARRAY_M(   name, _,    __, of_m, type, of_m2, ___, size_m, size, ... ) (__VB_C_FIRST(__VB_C_TYPE_RESOLVE4((name __VB_C_ROB(size)), __VB_C_ROB_IF_2(type), __VB_C_END_M))), __VA_ARGS__

			#define __VB_C_TYPE_RESOLVE4(...) __VB_C_TYPE_RESOLVE4_(__VA_ARGS__)
			#define __VB_C_TYPE_RESOLVE4_(name, x, mark, ...) __VB_C_TYPE_RESOLVE4##mark(name, x, __VA_ARGS__)
			#define __VB_C_TYPE_RESOLVE4__VB_C_START_M(   name, type,                                           ... ) ( __VB_C_ROB(type) name ), __VB_C_START_M, __VA_ARGS__
			#define __VB_C_TYPE_RESOLVE4__VB_C_END_M(     name, type,                                           ... ) ( __VB_C_ROB(type) name ), __VB_C_END_M,   __VA_ARGS__
			#define __VB_C_TYPE_RESOLVE4__VB_C_POINTER_M( name, _,     q, to_m,                                 ... ) __VB_C_TYPE_RESOLVE5((*__VB_C_RRB(q) name),    __VA_ARGS__)
			#define __VB_C_TYPE_RESOLVE4__VB_C_FUNC_M(    name, _,     q, of_m, args, ret_m,                    ... ) __VB_C_TYPE_RESOLVE5((*__VB_C_RRB(q) name) __VB_C_ROB(args), __VA_ARGS__)
			#define __VB_C_TYPE_RESOLVE4__VB_C_ARRAY_M(   name, _,    __, of_m, type, of_m2, ___, size_m, size, ... ) (__VB_C_FIRST(__VB_C_TYPE_RESOLVE5((name __VB_C_ROB(size)), __VB_C_ROB_IF_2(type), __VB_C_END_M))), __VA_ARGS__

			#define __VB_C_TYPE_RESOLVE5(...) __VB_C_TYPE_RESOLVE5_(__VA_ARGS__)
			#define __VB_C_TYPE_RESOLVE5_(name, x, mark, ...) __VB_C_TYPE_RESOLVE5##mark(name, x, __VA_ARGS__)
			#define __VB_C_TYPE_RESOLVE5__VB_C_START_M(   name, type,                                           ... ) ( __VB_C_ROB(type) name ), __VB_C_START_M, __VA_ARGS__
			#define __VB_C_TYPE_RESOLVE5__VB_C_END_M(     name, type,                                           ... ) ( __VB_C_ROB(type) name ), __VB_C_END_M,   __VA_ARGS__
			#define __VB_C_TYPE_RESOLVE5__VB_C_POINTER_M( name, _,     q, to_m,                                 ... ) __VB_C_TYPE_RESOLVE6((*__VB_C_RRB(q) name),    __VA_ARGS__)
			#define __VB_C_TYPE_RESOLVE5__VB_C_FUNC_M(    name, _,     q, of_m, args, ret_m,                    ... ) __VB_C_TYPE_RESOLVE6((*__VB_C_RRB(q) name) __VB_C_ROB(args), __VA_ARGS__)
			#define __VB_C_TYPE_RESOLVE5__VB_C_ARRAY_M(   name, _,    __, of_m, type, of_m2, ___, size_m, size, ... ) (__VB_C_FIRST(__VB_C_TYPE_RESOLVE6((name __VB_C_ROB(size)), __VB_C_ROB_IF_2(type), __VB_C_END_M))), __VA_ARGS__

			#define __VB_C_TYPE_RESOLVE6(...) __VB_C_TYPE_RESOLVE6_(__VA_ARGS__)
			#define __VB_C_TYPE_RESOLVE6_(name, x, mark, ...) __VB_C_TYPE_RESOLVE6##mark(name, x, __VA_ARGS__)
			#define __VB_C_TYPE_RESOLVE6__VB_C_START_M(   name, type,                                           ... ) ( __VB_C_ROB(type) name ), __VB_C_START_M, __VA_ARGS__
			#define __VB_C_TYPE_RESOLVE6__VB_C_END_M(     name, type,                                           ... ) ( __VB_C_ROB(type) name ), __VB_C_END_M,   __VA_ARGS__
			#define __VB_C_TYPE_RESOLVE6__VB_C_POINTER_M( name, _,     q, to_m,                                 ... ) __VB_C_TYPE_RESOLVE7((*__VB_C_RRB(q) name),    __VA_ARGS__)
			#define __VB_C_TYPE_RESOLVE6__VB_C_FUNC_M(    name, _,     q, of_m, args, ret_m,                    ... ) __VB_C_TYPE_RESOLVE7((*__VB_C_RRB(q) name) __VB_C_ROB(args), __VA_ARGS__)
			#define __VB_C_TYPE_RESOLVE6__VB_C_ARRAY_M(   name, _,    __, of_m, type, of_m2, ___, size_m, size, ... ) (__VB_C_FIRST(__VB_C_TYPE_RESOLVE7((name __VB_C_ROB(size)), __VB_C_ROB_IF_2(type), __VB_C_END_M))), __VA_ARGS__

			#define __VB_C_TYPE_RESOLVE7(...) __VB_C_TYPE_RESOLVE7_(__VA_ARGS__)
			#define __VB_C_TYPE_RESOLVE7_(name, x, mark, ...) __VB_C_TYPE_RESOLVE7##mark(name, x, __VA_ARGS__)
			#define __VB_C_TYPE_RESOLVE7__VB_C_START_M(   name, type,                                           ... ) ( __VB_C_ROB(type) name ), __VB_C_START_M, __VA_ARGS__
			#define __VB_C_TYPE_RESOLVE7__VB_C_END_M(     name, type,                                           ... ) ( __VB_C_ROB(type) name ), __VB_C_END_M,   __VA_ARGS__
			#define __VB_C_TYPE_RESOLVE7__VB_C_POINTER_M( name, _,     q, to_m,                                 ... ) __VB_C_TYPE_RESOLVE8((*__VB_C_RRB(q) name),    __VA_ARGS__)
			#define __VB_C_TYPE_RESOLVE7__VB_C_FUNC_M(    name, _,     q, of_m, args, ret_m,                    ... ) __VB_C_TYPE_RESOLVE8((*__VB_C_RRB(q) name) __VB_C_ROB(args), __VA_ARGS__)
			#define __VB_C_TYPE_RESOLVE7__VB_C_ARRAY_M(   name, _,    __, of_m, type, of_m2, ___, size_m, size, ... ) (__VB_C_FIRST(__VB_C_TYPE_RESOLVE8((name __VB_C_ROB(size)), __VB_C_ROB_IF_2(type), __VB_C_END_M))), __VA_ARGS__

			#define __VB_C_TYPE_RESOLVE8(...) __VB_C_TYPE_RESOLVE8_(__VA_ARGS__)
			#define __VB_C_TYPE_RESOLVE8_(name, x, mark, ...) __VB_C_TYPE_RESOLVE8##mark(name, x, __VA_ARGS__)
			#define __VB_C_TYPE_RESOLVE8__VB_C_START_M(   name, type,                                           ... ) ( __VB_C_ROB(type) name ), __VB_C_START_M, __VA_ARGS__
			#define __VB_C_TYPE_RESOLVE8__VB_C_END_M(     name, type,                                           ... ) ( __VB_C_ROB(type) name ), __VB_C_END_M,   __VA_ARGS__
			#define __VB_C_TYPE_RESOLVE8__VB_C_POINTER_M( name, _,     q, to_m,                                 ... ) __VB_C_TYPE_RESOLVE9((*__VB_C_RRB(q) name),    __VA_ARGS__)
			#define __VB_C_TYPE_RESOLVE8__VB_C_FUNC_M(    name, _,     q, of_m, args, ret_m,                    ... ) __VB_C_TYPE_RESOLVE9((*__VB_C_RRB(q) name) __VB_C_ROB(args), __VA_ARGS__)
			#define __VB_C_TYPE_RESOLVE8__VB_C_ARRAY_M(   name, _,    __, of_m, type, of_m2, ___, size_m, size, ... ) (__VB_C_FIRST(__VB_C_TYPE_RESOLVE9((name __VB_C_ROB(size)), __VB_C_ROB_IF_2(type), __VB_C_END_M))), __VA_ARGS__

			#define __VB_C_TYPE_RESOLVE9(...) __VB_C_TYPE_RESOLVE9_(__VA_ARGS__)
			#define __VB_C_TYPE_RESOLVE9_(name, x, mark, ...) __VB_C_TYPE_RESOLVE9##mark(name, x, __VA_ARGS__)
			#define __VB_C_TYPE_RESOLVE9__VB_C_START_M(   name, type,                                           ... ) ( __VB_C_ROB(type) name ), __VB_C_START_M, __VA_ARGS__
			#define __VB_C_TYPE_RESOLVE9__VB_C_END_M(     name, type,                                           ... ) ( __VB_C_ROB(type) name ), __VB_C_END_M,   __VA_ARGS__
			#define __VB_C_TYPE_RESOLVE9__VB_C_POINTER_M( name, _,     q, to_m,                                 ... ) __VB_C_TYPE_RESOLVE10((*__VB_C_RRB(q) name),    __VA_ARGS__)
			#define __VB_C_TYPE_RESOLVE9__VB_C_FUNC_M(    name, _,     q, of_m, args, ret_m,                    ... ) __VB_C_TYPE_RESOLVE10((*__VB_C_RRB(q) name) __VB_C_ROB(args), __VA_ARGS__)
			#define __VB_C_TYPE_RESOLVE9__VB_C_ARRAY_M(   name, _,    __, of_m, type, of_m2, ___, size_m, size, ... ) (__VB_C_FIRST(__VB_C_TYPE_RESOLVE10((name __VB_C_ROB(size)), __VB_C_ROB_IF_2(type), __VB_C_END_M))), __VA_ARGS__			
		// #pragma endregion
	// #pragma endregion

	/* CAST(expr AS <TYPE>) */
	#define CAST(...) __VB_C_CAST((__VA_ARGS__))
	#define __VB_C_CAST(exp, ...) ((__VB_C_DECL(, __VA_ARGS__, __VB_C_END_M)) exp)


	// #pragma region custom types
		/* TYPEDEF name AS <TYPE> END */
		#define TYPEDEF __VB_C_TYPEDEF __VB_C_LB (
		
		#define __VB_C_TYPEDEF(name, ...) typedef __VB_C_DECL(name, __VA_ARGS__);

		
		/*
		|	STRUCT name
			[START
				body]
			END
		|	STRUCT ANONYMOUS | ANON
				body
			END
		|	#define name(generic_args) STRUCT GENERIC \ // there has to be \ on end of 
				body                                   \ // every line, except last
			END
		*/
		#define STRUCT __VB_C_STRUCT __VB_C_LB (
		#define ANONYMOUS ), __VB_C_ANONYMOUS_M, (
		#define ANON ANONYMOUS
		#define GENERIC ), __VB_C_GENERIC_M, (

		#define __VB_C_STRUCT(name, mark, ...) __VB_C_STRUCT##mark(name, __VA_ARGS__) 
		#define __VB_C_STRUCT__VB_C_START_M(name, body, _) typedef struct __VB_C_ROB(name) __VB_C_ROB(name); struct __VB_C_ROB(name) { __VB_C_ROB(body) };
		#define __VB_C_STRUCT__VB_C_END_M(name, _)         typedef struct __VB_C_ROB(name) __VB_C_ROB(name);
		#define __VB_C_STRUCT__VB_C_ANONYMOUS_M(name, _, start_m, body, ...) struct { __VB_C_ROB(body) }
		#define __VB_C_STRUCT__VB_C_GENERIC_M( name, _, start_m, body, ...) struct { __VB_C_ROB(body) }


		/*
		ENUM name
		START
			body
		END
		*/
		#define ENUM __VB_C_ENUM __VB_C_LB (
		
		#define __VB_C_ENUM(name, mark, ...) __VB_C_ENUM##mark(name, __VA_ARGS__)
		#define __VB_C_ENUM__VB_C_START_M(name, body, _) typedef enum __VB_C_ROB(name) __VB_C_ROB(name); enum __VB_C_ROB(name) { __VB_C_ROB(body) };
		#define __VB_C_ENUM__VB_C_END_M(  name, __)      typedef enum __VB_C_ROB(name) __VB_C_ROB(name); 
	// #pragma endregion
// #pragma endregion

// #pragma region FUNCTION
	/*
	FUNCTION name OF (args) RETURNING <TYPE>
	[START
		code]
	END
	*/
	#define FUNCTION __VB_C_FUNCTION __VB_C_LB (
	#define OF ), __VB_C_OF_M, (
	#define RETURN return
	
	#define __VB_C_FUNCTION(name, of_m, args, ret_m, ...) __VB_C_FUNCTION0(__VB_C_TYPE_RESOLVE((__VB_C_ROB(name) __VB_C_ROB(args)), __VA_ARGS__))
	// #define __VB_C_FUNCTION0(...) __VB_C_FUNCTION0_(__VA_ARGS__) // __VB_C_FUNCTION1(__VA_ARGS__) 
	#define __VB_C_FUNCTION0(...) __VB_C_FUNCTION1(__VA_ARGS__) 
	// #define __VB_C_FUNCTION0_(...) #__VA_ARGS__ // __VB_C_FUNCTION1(__VA_ARGS__) 
	#define __VB_C_FUNCTION1(decl, mark, ...) __VB_C_FUNCTION1##mark(decl, __VA_ARGS__)
	#define __VB_C_FUNCTION1__VB_C_START_M( decl, body, ...) __VB_C_ROB(decl) { __VB_C_ROB(body) }
	#define __VB_C_FUNCTION1__VB_C_END_M(   decl,       ...) __VB_C_ROB(decl) ;
// #pragma endregion



#endif // VB_H

