import { Schema } from "./schema";
import { ByteBuffer } from "./bb";
export declare function compileSchemaJS(schema: Schema | Uint8Array | string | ByteBuffer): string;
export declare function compileSchema(schema: Schema): any;
