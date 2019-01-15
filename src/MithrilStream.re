/* See xstream bindings
   https://gitlab.com/j3a-solutions/bs-xstream/blob/master/src/xstream_stream.re
   */
type callbackFn = ('a) => 'b;
type lifterFn = ('a) => 'b;
type applyFn = Stream.t('a) => Stream.t('b)
type combinerFn = (array(Stream.t('a)), array(Stream.t('b))) => 'c;

module Stream = {
  type t('a) = {    
    end: unit = "",
    of: 'a => Stream.t('b),
    map: (callbackFn) => Stream.t('a),
    ap: (applyFn) => Stream.t('a)
  };
};


[@bs.module "mithril/stream"] 
external stream: (~value: 'b, unit) => Stream.t('a) = "Stream";
[@bs.module "mithril/stream"]
external combine: (combinerFn, array(Stream.t('b))) => Stream.t('a) = "";
[@bs.module "mithril/stream"]
external map: ('a => 'c, Stream.t('a)) => Stream.t('c) = "";
[@bs.module "mithril/stream"] 
external scan: ('a => 'c, 'd, Stream.t('a)) => 'c = "";
[@bs.module "mithril/stream"]
external merge: array(Stream.t('a)) => Stream.t('a) = "";
[@bs.module "mithril/stream"]
external scanMerge: (pairs: 'a, acc: 'c) => Stream.t('a) = "";
[@bs.module "mithril/stream"] 
external lifter: (array(Stream.t('a))) => 'c = "";
[@bs.module "mithril/stream"] external lift: (lifterFn, array(Stream.t('a))) => Stream.t('a) = "";