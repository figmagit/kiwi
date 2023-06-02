// This is a small entry point intended for use in the browser

import { encodeBinarySchema, decodeBinarySchema } from './binary'
import { compileSchema } from './js'
import { parseSchema } from './parser'

export { encodeBinarySchema, decodeBinarySchema, compileSchema, parseSchema }
