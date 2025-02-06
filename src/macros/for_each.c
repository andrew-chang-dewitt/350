/* FOR_EACH(macro, ...)
 * --------------------
 * A macro (& necessary children) for calling a given `macro` over a given list
 * of arguments (accessed via __VA_ARGS__). Max number of args to iterate over
 * is limited by the number of args specified/macros defined in aforementioned
 * necessary children, currently at 100, but could be changed.
 *
 * Usage:
 *
 * ```c
 * #define PRINTLN(msg) printf("%s\n", msg);
 * FOR_EACH(PRINTLN, "this prints multiple messages", "I can give it a bunch",
 *          "& it will print each on", "their own line", "because why not?")
 * ```
 *
 * which outputs:
 *
 * ```
 * this prints multiple messages
 * I can give it a bunch
 * & it will print each on
 * their own line
 * because why not?
 * ```
 *
 * largely informed by Daniel Hardman's [blog post][1] & [gist][2] on the topic.
 *
 * [1]: https://codecraft.co/variadic-macros-tricks.html
 * [2]: https://gist.github.com/dhh1128/d1dd24b492819c65f1e1
 */

#ifndef FOR_EACH

/* _GET_NTH_ARG
 * ------------
 * returns the nth argument from the given list of args
 * NOTE: limited to picking from a maximum of 101 arguments
 */
#define _GET_NTH_ARG(                                                          \
    _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16,     \
    _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, \
    _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, \
    _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, \
    _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72, _73, _74, _75, _76, \
    _77, _78, _79, _80, _81, _82, _83, _84, _85, _86, _87, _88, _89, _90, _91, \
    _92, _93, _94, _95, _96, _97, _98, _99, _100, N, ...)                      \
  N

/* _fe_N
 * -----
 * macros to match the current arg to the correct airty in our FOR_EACH
 * arg list
 * NOTE: limited to up to 101 args
 */
#define _fe_0(macro, ...)
#define _fe_1(macro, arg) macro(arg)
#define _fe_2(macro, arg, ...) macro(arg) _fe_1(macro, __VA_ARGS__)
#define _fe_3(macro, arg, ...) macro(arg) _fe_2(macro, __VA_ARGS__)
#define _fe_4(macro, arg, ...) macro(arg) _fe_3(macro, __VA_ARGS__)
#define _fe_5(macro, arg, ...) macro(arg) _fe_4(macro, __VA_ARGS__)
#define _fe_6(macro, arg, ...) macro(arg) _fe_5(macro, __VA_ARGS__)
#define _fe_7(macro, arg, ...) macro(arg) _fe_6(macro, __VA_ARGS__)
#define _fe_8(macro, arg, ...) macro(arg) _fe_7(macro, __VA_ARGS__)
#define _fe_9(macro, arg, ...) macro(arg) _fe_8(macro, __VA_ARGS__)
#define _fe_10(macro, arg, ...) macro(arg) _fe_9(macro, __VA_ARGS__)
#define _fe_11(macro, arg, ...) macro(arg) _fe_10(macro, __VA_ARGS__)
#define _fe_12(macro, arg, ...) macro(arg) _fe_11(macro, __VA_ARGS__)
#define _fe_13(macro, arg, ...) macro(arg) _fe_12(macro, __VA_ARGS__)
#define _fe_14(macro, arg, ...) macro(arg) _fe_13(macro, __VA_ARGS__)
#define _fe_15(macro, arg, ...) macro(arg) _fe_14(macro, __VA_ARGS__)
#define _fe_16(macro, arg, ...) macro(arg) _fe_15(macro, __VA_ARGS__)
#define _fe_17(macro, arg, ...) macro(arg) _fe_16(macro, __VA_ARGS__)
#define _fe_18(macro, arg, ...) macro(arg) _fe_17(macro, __VA_ARGS__)
#define _fe_19(macro, arg, ...) macro(arg) _fe_18(macro, __VA_ARGS__)
#define _fe_20(macro, arg, ...) macro(arg) _fe_19(macro, __VA_ARGS__)
#define _fe_21(macro, arg, ...) macro(arg) _fe_20(macro, __VA_ARGS__)
#define _fe_22(macro, arg, ...) macro(arg) _fe_21(macro, __VA_ARGS__)
#define _fe_23(macro, arg, ...) macro(arg) _fe_22(macro, __VA_ARGS__)
#define _fe_24(macro, arg, ...) macro(arg) _fe_23(macro, __VA_ARGS__)
#define _fe_25(macro, arg, ...) macro(arg) _fe_24(macro, __VA_ARGS__)
#define _fe_26(macro, arg, ...) macro(arg) _fe_25(macro, __VA_ARGS__)
#define _fe_27(macro, arg, ...) macro(arg) _fe_26(macro, __VA_ARGS__)
#define _fe_28(macro, arg, ...) macro(arg) _fe_27(macro, __VA_ARGS__)
#define _fe_29(macro, arg, ...) macro(arg) _fe_28(macro, __VA_ARGS__)
#define _fe_30(macro, arg, ...) macro(arg) _fe_29(macro, __VA_ARGS__)
#define _fe_31(macro, arg, ...) macro(arg) _fe_30(macro, __VA_ARGS__)
#define _fe_32(macro, arg, ...) macro(arg) _fe_31(macro, __VA_ARGS__)
#define _fe_33(macro, arg, ...) macro(arg) _fe_32(macro, __VA_ARGS__)
#define _fe_34(macro, arg, ...) macro(arg) _fe_33(macro, __VA_ARGS__)
#define _fe_35(macro, arg, ...) macro(arg) _fe_34(macro, __VA_ARGS__)
#define _fe_36(macro, arg, ...) macro(arg) _fe_35(macro, __VA_ARGS__)
#define _fe_37(macro, arg, ...) macro(arg) _fe_36(macro, __VA_ARGS__)
#define _fe_38(macro, arg, ...) macro(arg) _fe_37(macro, __VA_ARGS__)
#define _fe_39(macro, arg, ...) macro(arg) _fe_38(macro, __VA_ARGS__)
#define _fe_40(macro, arg, ...) macro(arg) _fe_39(macro, __VA_ARGS__)
#define _fe_41(macro, arg, ...) macro(arg) _fe_40(macro, __VA_ARGS__)
#define _fe_42(macro, arg, ...) macro(arg) _fe_41(macro, __VA_ARGS__)
#define _fe_43(macro, arg, ...) macro(arg) _fe_42(macro, __VA_ARGS__)
#define _fe_44(macro, arg, ...) macro(arg) _fe_43(macro, __VA_ARGS__)
#define _fe_45(macro, arg, ...) macro(arg) _fe_44(macro, __VA_ARGS__)
#define _fe_46(macro, arg, ...) macro(arg) _fe_45(macro, __VA_ARGS__)
#define _fe_47(macro, arg, ...) macro(arg) _fe_46(macro, __VA_ARGS__)
#define _fe_48(macro, arg, ...) macro(arg) _fe_47(macro, __VA_ARGS__)
#define _fe_49(macro, arg, ...) macro(arg) _fe_48(macro, __VA_ARGS__)
#define _fe_50(macro, arg, ...) macro(arg) _fe_49(macro, __VA_ARGS__)
#define _fe_51(macro, arg, ...) macro(arg) _fe_50(macro, __VA_ARGS__)
#define _fe_52(macro, arg, ...) macro(arg) _fe_51(macro, __VA_ARGS__)
#define _fe_53(macro, arg, ...) macro(arg) _fe_52(macro, __VA_ARGS__)
#define _fe_54(macro, arg, ...) macro(arg) _fe_53(macro, __VA_ARGS__)
#define _fe_55(macro, arg, ...) macro(arg) _fe_54(macro, __VA_ARGS__)
#define _fe_56(macro, arg, ...) macro(arg) _fe_55(macro, __VA_ARGS__)
#define _fe_57(macro, arg, ...) macro(arg) _fe_56(macro, __VA_ARGS__)
#define _fe_58(macro, arg, ...) macro(arg) _fe_57(macro, __VA_ARGS__)
#define _fe_59(macro, arg, ...) macro(arg) _fe_58(macro, __VA_ARGS__)
#define _fe_60(macro, arg, ...) macro(arg) _fe_59(macro, __VA_ARGS__)
#define _fe_61(macro, arg, ...) macro(arg) _fe_60(macro, __VA_ARGS__)
#define _fe_62(macro, arg, ...) macro(arg) _fe_61(macro, __VA_ARGS__)
#define _fe_63(macro, arg, ...) macro(arg) _fe_62(macro, __VA_ARGS__)
#define _fe_64(macro, arg, ...) macro(arg) _fe_63(macro, __VA_ARGS__)
#define _fe_65(macro, arg, ...) macro(arg) _fe_64(macro, __VA_ARGS__)
#define _fe_66(macro, arg, ...) macro(arg) _fe_65(macro, __VA_ARGS__)
#define _fe_67(macro, arg, ...) macro(arg) _fe_66(macro, __VA_ARGS__)
#define _fe_68(macro, arg, ...) macro(arg) _fe_67(macro, __VA_ARGS__)
#define _fe_69(macro, arg, ...) macro(arg) _fe_68(macro, __VA_ARGS__)
#define _fe_70(macro, arg, ...) macro(arg) _fe_69(macro, __VA_ARGS__)
#define _fe_71(macro, arg, ...) macro(arg) _fe_70(macro, __VA_ARGS__)
#define _fe_72(macro, arg, ...) macro(arg) _fe_71(macro, __VA_ARGS__)
#define _fe_73(macro, arg, ...) macro(arg) _fe_72(macro, __VA_ARGS__)
#define _fe_74(macro, arg, ...) macro(arg) _fe_73(macro, __VA_ARGS__)
#define _fe_75(macro, arg, ...) macro(arg) _fe_74(macro, __VA_ARGS__)
#define _fe_76(macro, arg, ...) macro(arg) _fe_75(macro, __VA_ARGS__)
#define _fe_77(macro, arg, ...) macro(arg) _fe_76(macro, __VA_ARGS__)
#define _fe_78(macro, arg, ...) macro(arg) _fe_77(macro, __VA_ARGS__)
#define _fe_79(macro, arg, ...) macro(arg) _fe_78(macro, __VA_ARGS__)
#define _fe_80(macro, arg, ...) macro(arg) _fe_79(macro, __VA_ARGS__)
#define _fe_81(macro, arg, ...) macro(arg) _fe_80(macro, __VA_ARGS__)
#define _fe_82(macro, arg, ...) macro(arg) _fe_81(macro, __VA_ARGS__)
#define _fe_83(macro, arg, ...) macro(arg) _fe_82(macro, __VA_ARGS__)
#define _fe_84(macro, arg, ...) macro(arg) _fe_83(macro, __VA_ARGS__)
#define _fe_85(macro, arg, ...) macro(arg) _fe_84(macro, __VA_ARGS__)
#define _fe_86(macro, arg, ...) macro(arg) _fe_85(macro, __VA_ARGS__)
#define _fe_87(macro, arg, ...) macro(arg) _fe_86(macro, __VA_ARGS__)
#define _fe_88(macro, arg, ...) macro(arg) _fe_87(macro, __VA_ARGS__)
#define _fe_89(macro, arg, ...) macro(arg) _fe_88(macro, __VA_ARGS__)
#define _fe_90(macro, arg, ...) macro(arg) _fe_89(macro, __VA_ARGS__)
#define _fe_91(macro, arg, ...) macro(arg) _fe_90(macro, __VA_ARGS__)
#define _fe_92(macro, arg, ...) macro(arg) _fe_91(macro, __VA_ARGS__)
#define _fe_93(macro, arg, ...) macro(arg) _fe_92(macro, __VA_ARGS__)
#define _fe_94(macro, arg, ...) macro(arg) _fe_93(macro, __VA_ARGS__)
#define _fe_95(macro, arg, ...) macro(arg) _fe_94(macro, __VA_ARGS__)
#define _fe_96(macro, arg, ...) macro(arg) _fe_95(macro, __VA_ARGS__)
#define _fe_97(macro, arg, ...) macro(arg) _fe_96(macro, __VA_ARGS__)
#define _fe_98(macro, arg, ...) macro(arg) _fe_97(macro, __VA_ARGS__)
#define _fe_99(macro, arg, ...) macro(arg) _fe_98(macro, __VA_ARGS__)

#define FOR_EACH(macro, ...)                                                   \
  _GET_NTH_ARG(                                                                \
      "_", __VA_ARGS__, _fe_99, _fe_98, _fe_97, _fe_96, _fe_95, _fe_94,        \
      _fe_93, _fe_92, _fe_91, _fe_90, _fe_89, _fe_88, _fe_87, _fe_86, _fe_85,  \
      _fe_84, _fe_83, _fe_82, _fe_81, _fe_80, _fe_79, _fe_78, _fe_77, _fe_76,  \
      _fe_75, _fe_74, _fe_73, _fe_72, _fe_71, _fe_70, _fe_69, _fe_68, _fe_67,  \
      _fe_66, _fe_65, _fe_64, _fe_63, _fe_62, _fe_61, _fe_60, _fe_59, _fe_58,  \
      _fe_57, _fe_56, _fe_55, _fe_54, _fe_53, _fe_52, _fe_51, _fe_50, _fe_49,  \
      _fe_48, _fe_47, _fe_46, _fe_45, _fe_44, _fe_43, _fe_42, _fe_41, _fe_40,  \
      _fe_39, _fe_38, _fe_37, _fe_36, _fe_35, _fe_34, _fe_33, _fe_32, _fe_31,  \
      _fe_30, _fe_29, _fe_28, _fe_27, _fe_26, _fe_25, _fe_24, _fe_23, _fe_22,  \
      _fe_21, _fe_20, _fe_19, _fe_18, _fe_17, _fe_16, _fe_15, _fe_14, _fe_13,  \
      _fe_12, _fe_11, _fe_10, _fe_9, _fe_8, _fe_7, _fe_6, _fe_5, _fe_4, _fe_3, \
      _fe_2, _fe_1, _fe_0)(macro, __VA_ARGS__)

#endif
