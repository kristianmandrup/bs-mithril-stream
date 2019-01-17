/** Need to uncurry to prevent generating JS like x(0)
    See https://bucklescript.github.io/docs/en/function#curry-uncurry */
type t('a) = (. unit) => 'a;

/* See
   https://bucklescript.github.io/docs/en/import-export#import-a-default-value
   Test: let s = make(1); */
[@bs.module] external make: 'a => t('a) = "mithril/stream";

/* See https://bucklescript.github.io/docs/en/common-data-types#tuple
   Test:
   let s1 = make(1);
   let s2 = make(2);
   let s3 = combine2((. s1, s2) => s1(. ) + s2(. ), (s1, s2)); */
[@bs.module "mithril/stream"] external combine2: (
  (. t('a1), t('a2)) => 'b,
  (t('a1), t('a2)),
) => t('b) = "combine";

[@bs.module "mithril/stream"] external combine3: (
  (. t('a1), t('a2), t('a3)) => 'b,
  (t('a1), t('a2), t('a3)),
) => t('b) = "combine";

[@bs.module "mithril/stream"] external combine4: (
  (. t('a1), t('a2), t('a3), t('a4)) => 'b,
  (t('a1), t('a2), t('a3), t('a4)),
) => t('b) = "combine";

[@bs.module "mithril/stream"]
external map: ('a => 'c, Stream.t('a)) => Stream.t('c) = "";


/* Test:
   let s = make(1);
   let t = map((. x) => x + 1, s); */
[@bs.send.pipe: t('a)] external map: ((. 'a) => 'b) => t('b) = "";

[@bs.module "mithril/stream"] 
external scan: ('a => 'c, 'd, Stream.t('a)) => 'c = "";

[@bs.module "mithril/stream"]
external merge: array(Stream.t('a)) => Stream.t('a) = "";

[@bs.module "mithril/stream"]
external scanMerge: (pairs: 'a, acc: 'c) => Stream.t('a) = "";

[@bs.module "mithril/stream"] 
external lifter: (array(Stream.t('a))) => 'c = "";

[@bs.module "mithril/stream"] external lift: (lifterFn, array(Stream.t('a))) => Stream.t('a) = "";