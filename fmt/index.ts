import fs from 'fs';
import Parser from 'tree-sitter';
import {Tree, SyntaxNode} from 'tree-sitter';
import gsql from 'tree-sitter-gsql';

const parser = new Parser();
parser.setLanguage(gsql);

let sourceCode = fs.readFileSync('../example.gsql', 'utf8');

// todo do this in traversal in order to ignore comments
// caps keywords
const keywords = [
    'ACCUM',
    'ADD',
    'ALL',
    'ALLOCATE',
    'ALTER',
    'AND',
    'ANY',
    'AS',
    'ASC',
    'AVG',
    'BAG',
    'BATCH',
    'BETWEEN',
    'BIGINT',
    'BLOB',
    'BOOL',
    'BOOLEAN',
    'BOTH',
    'BREAK',
    'BY',
    'CALL',
    'CASCADE',
    'CASE',
    'CATCH',
    'CHAR',
    'CHARACTER',
    'CHECK',
    'CLOB',
    'COALESCE',
    'COMPRESS',
    'CONST',
    'CONSTRAINT',
    'CONTINUE',
    'COST',
    'COUNT',
    'CREATE',
    'CURRENT_DATE',
    'CURRENT_TIME',
    'CURRENT_TIMESTAMP',
    'CURSOR',
    'KAFKA',
    'S3',
    'DATETIME',
    'DATETIME_ADD',
    'DATETIME_SUB',
    'DAY',
    'DATETIME_DIFF',
    'DATETIME_TO_EPOCH',
    'DATETIME_FORMAT',
    'DECIMAL',
    'DECLARE',
    'DELETE',
    'DESC',
    'DISTRIBUTED',
    'DO',
    'DOUBLE',
    'DROP',
    'EDGE',
    'ELSE',
    'ELSEIF',
    'EPOCH_TO_DATETIME',
    'END',
    'ESCAPE',
    'EXCEPTION',
    'EXISTS',
    'FALSE',
    'FILE',
    'SYS.FILE_NAME',
    'FILTER',
    'FIXED_BINARY',
    'FLOAT',
    'FOR',
    'FOREACH',
    'FROM',
    'GLOBAL',
    'GRANTS',
    'GRAPH',
    'GROUP',
    'GROUPBYACCUM',
    'HAVING',
    'HOUR',
    'HEADER',
    'HEAPACCUM',
    'IF',
    'IGNORE',
    'SYS.INTERNAL_ID',
    'IN',
    'INDEX',
    'INPUT_LINE_FILTER',
    'INSERT',
    'INT',
    'INTERSECT',
    'INT8',
    'INT16',
    'INT32',
    'INT32_T',
    'INT64_T',
    'INTEGER',
    'INTERPRET',
    'INTO',
    'IS',
    'ISEMPTY',
    'JOB',
    'JOIN',
    'JSONARRAY',
    'JSONOBJECT',
    'KEY',
    'LEADING',
    'LIKE',
    'LIMIT',
    'LIST',
    'LOAD',
    'LOADACCUM',
    'LOG',
    'LONG',
    'MAP',
    'MINUTE',
    'NOBODY',
    'NOT',
    'NOW',
    'NULL',
    'OFFSET',
    'ON',
    'OR',
    'ORDER',
    'PINNED',
    'POST_ACCUM',
    'POST-ACCUM',
    'PRIMARY',
    'PRIMARY_ID',
    'PRINT',
    'PROXY',
    'QUERY',
    'QUIT',
    'RAISE',
    'RANGE',
    'REDUCE',
    'REPLACE',
    'RESET_COLLECTION_ACCUM',
    'RETURN',
    'RETURNS',
    'SAMPLE',
    'SECOND',
    'SELECT',
    'SELECTVERTEX',
    'SET',
    'STATIC',
    'STRING',
    'SUM',
    'TARGET',
    'TEMP_TABLE',
    'THEN',
    'TO',
    'TO_CSV',
    'TO_DATETIME',
    'TRAILING',
    'TRANSLATESQL',
    'TRIM',
    'TRUE',
    'TRY',
    'TUPLE',
    'TYPEDEF',
    'UINT',
    'UINT8',
    'UINT16',
    'UINT32',
    'UINT8_T',
    'UINT32_T',
    'UINT64_T',
    'UNION',
    'UPDATE',
    'UPSERT',
    'USING',
    'VALUES',
    'VERTEX',
    'WHEN',
    'WHERE',
    'WHILE',
    'WITH',
    'GSQL_SYS_TAG',
    '_INTERNAL_ATTR_TAG',
    'GSQL Non-Reserved Keywords',
    'These keywords in the language are non-reserved',
    ' so users may use them for user-defined identifiers.',
    'Non-reserved keyword list',
    'ABORT',
    'ACL',
    'ADMIN',
    'API',
    'APPROX_COUNT',
    'ATTRIBUTE',
    'BEGIN',
    'BITINDEX',
    'CHANGE',
    'CLEAR',
    'CONCAT',
    'DATA',
    'DATA_SOURCE',
    'DECRYPT',
    'DEFAULT',
    'DEFINE',
    'DESCRIPTION',
    'DIRECTED',
    'EMPTY',
    'EXECUTE',
    'EXIT',
    'EXPORT',
    'TG_EXPRFUNCTIONS',
    'TG_EXPRUTIL',
    'EXTERN',
    'FILENAME',
    'FLATTEN',
    'FLATTEN_JSON_ARRAY',
    'GEN-DATA',
    'GET',
    'GRANT',
    'HELP',
    'ICON',
    'IMPORT',
    'INSTALL',
    'INTERVAL',
    'JSON',
    'LEADER',
    'LOADING',
    'LOCAL',
    'LS',
    'MONTH',
    'MAX',
    'MIN',
    'MINUS',
    'NUMERIC',
    'OF',
    'OPTION',
    'OVERWRITE',
    'OWNER',
    'PAIR',
    'PASSWORD',
    'PRIVILEGE',
    'PUT',
    'READ',
    'RECOMPILE',
    'REJECT_LINE_RULE',
    'RESUME',
    'REVOKE',
    'ROLE',
    'RUN',
    'SCHEMA',
    'SCHEMA_CHANGE',
    'SECONDARY_ID',
    'SECRET',
    'SECURED',
    'SEPARATOR',
    'SHOW',
    'SPLIT',
    'STATS',
    'STATUS',
    'STORE',
    'SUBSTR',
    'SYNTAX',
    'TAG',
    'TAGS',
    'TEMPLATE',
    'TOKEN',
    'TOKEN_LEN',
    'TOKENBANK',
    'TO_FLOAT',
    'TO_INT',
    'UNDIRECTED',
    'USE',
    'USER',
    'USERS',
    'VAL',
    'VECTOR',
    'VERSION',
    'VOID',
    'SINGLE',
    'LEGACY',
    'YEAR',
];
let srcCaps = '';
sourceCode.split('\n').forEach((l) => {
    srcCaps +=
        l
            .split(' ')
            .map((w: string) => {
                if (keywords.includes(w.toUpperCase())) {
                    return w.toUpperCase();
                }
                return w;
            })
            .join(' ') + '\n';
});

console.log(srcCaps);
// //traverse
// const tree: Tree = parser.parse(sourceCode);

// function traverse_tree(tree: Tree) {
//     const cursor = tree.walk();
//     let reachedRoot = false;
//     let currentNode: SyntaxNode;

//     while (!reachedRoot) {
//         currentNode = cursor.currentNode;
//         if (
//             // currentNode.childCount == 0 || !
//             !currentNode.isNamed
//         ) {
//             // console.log(cursor.currentNode);
//             console.log(currentNode.text, currentNode.type);
//             // console.log(currentNode.fie);
//         }

//         if (cursor.gotoFirstChild()) {
//             continue;
//         }
//         if (cursor.gotoNextSibling()) {
//             continue;
//         }

//         let retracing = true;
//         while (retracing) {
//             if (!cursor.gotoParent()) {
//                 retracing = false;
//                 reachedRoot = true;
//             }

//             if (cursor.gotoNextSibling()) {
//                 retracing = false;
//             }
//         }
//     }
// }

// traverse_tree(tree);
