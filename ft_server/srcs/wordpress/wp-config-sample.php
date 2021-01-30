<?php
/**
 * The base configuration for WordPress
 *
 * The wp-config.php creation script uses this file during the
 * installation. You don't have to use the web site, you can
 * copy this file to "wp-config.php" and fill in the values.
 *
 * This file contains the following configurations:
 *
 * * MySQL settings
 * * Secret keys
 * * Database table prefix
 * * ABSPATH
 *
 * @link https://wordpress.org/support/article/editing-wp-config-php/
 *
 * @package WordPress
 */

// ** MySQL settings - You can get this info from your web host ** //
/** The name of the database for WordPress */
define( 'DB_NAME', 'wordpress' );

/** MySQL database username */
define( 'DB_USER', 'wordpress' );

/** MySQL database password */
define( 'DB_PASSWORD', 'wordpress' );

/** MySQL hostname */
define( 'DB_HOST', 'localhost' );

/** Database Charset to use in creating database tables. */
define( 'DB_CHARSET', 'utf8' );

/** The Database Collate type. Don't change this if in doubt. */
define( 'DB_COLLATE', '' );

/**#@+
 * Authentication Unique Keys and Salts.
 *
 * Change these to different unique phrases!
 * You can generate these using the {@link https://api.wordpress.org/secret-key/1.1/salt/ WordPress.org secret-key service}
 * You can change these at any point in time to invalidate all existing cookies. This will force all users to have to log in again.
 *
 * @since 2.6.0
 */
define('AUTH_KEY',         'zU8+EHK*4*[<xkEeS|pP7/H5ucNC0+>&y!X(%0?$[@PZ =5}GadB+:A|3%^Yn=v(');
define('SECURE_AUTH_KEY',  '3g7+1^MEE)KU@5gALuA71I`0{p9l/*(Q15pI4vlm^*s?RmS1hc?G7ah+.?`r/y ]');
define('LOGGED_IN_KEY',    'ICm7$;C [^65mY=;e}@?D6b!+ta6y}?rSKb-6/c-2fit0?QcU;W+-2mnc@:y)LVc');
define('NONCE_KEY',        'k>qr|GU<P;H5lrfY.+}u9gp0bRA/J#g7MWwNByp;3`QW3GtE;e`[9AI[Pk!A3cyC');
define('AUTH_SALT',        'z;{-43 +pD@S}hHb^Qu8B>AX-z&6(}U=*ghmm-Vc;|r7{p}SeK]${|Z(60U7@1?!');
define('SECURE_AUTH_SALT', ':Rj35ym]))Tf{S+KwyALU6?-{]HPW3=%>[74qjh5uGpvc;mdsA%V|tMT5u|)F>M2');
define('LOGGED_IN_SALT',   '4b9v*H_J+`8TanLzd#; s}U5{Nz0#NANrlR|@hwm@3|%-jamYDzL>M#pny6c{g||');
define('NONCE_SALT',       'J!O2nT!VIkbF1_K6uvf0?lj+~Eg`L6-;*#.z:dSSSOO~z6g<i[fjSk-E/Ty&X&{O');
/**#@-*/

/**
 * WordPress Database Table prefix.
 *
 * You can have multiple installations in one database if you give each
 * a unique prefix. Only numbers, letters, and underscores please!
 */
$table_prefix = 'wp_';

/**
 * For developers: WordPress debugging mode.
 *
 * Change this to true to enable the display of notices during development.
 * It is strongly recommended that plugin and theme developers use WP_DEBUG
 * in their development environments.
 *
 * For information on other constants that can be used for debugging,
 * visit the documentation.
 *
 * @link https://wordpress.org/support/article/debugging-in-wordpress/
 */
define( 'WP_DEBUG', false );

/* That's all, stop editing! Happy publishing. */

/** Absolute path to the WordPress directory. */
if ( ! defined( 'ABSPATH' ) ) {
	define( 'ABSPATH', __DIR__ . '/' );
}

/** Sets up WordPress vars and included files. */
require_once ABSPATH . 'wp-settings.php';
