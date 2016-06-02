struct gl_texture_object;
struct gl_shared_state;
typedef int GLuint;

extern struct gl_texture_object *
gl_alloc_texture_object( struct gl_shared_state *shared, GLuint name,
                         GLuint dimensions );

extern void gl_free_texture_object( struct gl_shared_state *shared,
                                    struct gl_texture_object *t );


