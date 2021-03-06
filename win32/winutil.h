/*
   +----------------------------------------------------------------------+
   | PHP Version 7                                                        |
   +----------------------------------------------------------------------+
   | Copyright (c) 1997-2018 The PHP Group                                |
   +----------------------------------------------------------------------+
   | This source file is subject to version 3.01 of the PHP license,      |
   | that is bundled with this package in the file LICENSE, and is        |
   | available through the world-wide-web at the following url:           |
   | http://www.php.net/license/3_01.txt                                  |
   | If you did not receive a copy of the PHP license and are unable to   |
   | obtain it through the world-wide-web, please send a note to          |
   | license@php.net so we can mail you a copy immediately.               |
   +----------------------------------------------------------------------+
   | Author:                                                              |
   +----------------------------------------------------------------------+
 */

#ifndef PHP_WIN32_WINUTIL_H
#define PHP_WIN32_WINUTIL_H

#ifdef PHP_EXPORTS
# define PHP_WINUTIL_API __declspec(dllexport)
#else
# define PHP_WINUTIL_API __declspec(dllimport)
#endif

PHP_WINUTIL_API char *php_win32_error_to_msg(HRESULT error);

#define php_win_err()	php_win32_error_to_msg(GetLastError())
int php_win32_check_trailing_space(const char * path, const size_t path_len);
PHP_WINUTIL_API int php_win32_get_random_bytes(unsigned char *buf, size_t size);
#ifdef PHP_EXPORTS
BOOL php_win32_init_random_bytes(void);
BOOL php_win32_shutdown_random_bytes(void);
#endif

#if !defined(ECURDIR)
# define ECURDIR        EACCES
#endif /* !ECURDIR */
#if !defined(ENOSYS)
# define ENOSYS         EPERM
#endif /* !ENOSYS */

PHP_WINUTIL_API int php_win32_code_to_errno(unsigned long w32Err);

#define SET_ERRNO_FROM_WIN32_CODE(err) \
	do { \
	int ern = php_win32_code_to_errno(err); \
	SetLastError(err); \
	_set_errno(ern); \
	} while (0)

PHP_WINUTIL_API char *php_win32_get_username(void);

#endif

/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: sw=4 ts=4 fdm=marker
 * vim<600: sw=4 ts=4
 */
