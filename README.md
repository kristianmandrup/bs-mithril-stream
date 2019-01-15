# bs-mithril-stream

Bucklescript bindings for [mithril](https://github.com/MithrilJS/mithril.js) stream library.

## Use

mithril-stream can be used with modern state management solutions like [Meiosis](https://meiosis.js.org/) to great effect. No need for Virtual DOMs or other "complex machinery" at this point in time ;)

## Writing bindings

To help write bucklescript bindings for this lib (and hence make it usable from ReasonML) see the [FFI cheatsheet](https://github.com/glennsl/bucklescript-ffi-cheatsheet) and go for it!

### Install

`npm i bs-mithril-stream`

Add `bs-mithril-stream` to `dependencies` in `bsconfig.json`

## Api

See [mithril stream API](https://github.com/MithrilJS/mithril.js/blob/master/docs/stream.md#signature)

### Api changes

- To force the stream to end, use `Stream.end(~force: true)`

### Usage

```javascript
open MithrilStream;
let number = stream(5);
let fn = strm => strm;
let combined = combine(fn, [32]);
```

## Build

```
npm run build
```

## Watch

```
npm run watch
```

## Editor

If you use `vscode`, Press `Windows + Shift + B` it will build automatically
