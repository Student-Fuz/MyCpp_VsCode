cmake_minimum_required(VERSION 3.21)
project(CPP)

set(CMAKE_CXX_STANDARD 14)

############################################
#              basic_grammar
############################################

#IO---Basic_IO
add_executable(basic_IO basic_grammar/IO/basic_IO/IO.cpp basic_grammar/pointer/char_pointer.cpp)

#IO---File_Stream
add_executable(file_stream basic_grammar/IO/file_Stream/file_Stream.cpp)

#basic_grammar---stringstream
add_executable(stringstream basic_grammar/string/stringstream/stringstream.cpp)

#basic_grammar---const
add_executable(const basic_grammar/const/const.cpp)

#basic_grammar---reference
add_executable(reference basic_grammar/reference/reference/reference.cpp)

#basic_grammar---rvalue_reference
add_executable(char_pointer basic_grammar/pointer/char_pointer.cpp)

#basic_grammar---rvalue_reference
add_executable(rvalue_reference basic_grammar/reference/reference/rvalue_reference.cpp)


############################################
#                   OOP
############################################

#oop---deepshallow_copy
add_executable(oop_deepshallow_copy OOP/deepshallow_copy/Teacher.cpp)

#oop---overload
add_executable(oop_overload OOP/overload/overload.cpp)

#oop---operator_overload
add_executable(oop_operator_overload OOP/overload/Operator_overload.cpp)

#oop---assign_operator_overload
add_executable(oop_assign OOP/overload/assign.cpp)

#oop---++_overload
add_executable(oop_operator_plusplus_overload OOP/overload/Operator_plusplus_overload.cpp)

#oop---friend
add_executable(oop_friend OOP/access_authority/Friend.cpp)

#oop---test
add_executable(oop_test OOP/test/test.cpp OOP/test/test.h)

#oop---inherit
add_executable(oop_inherit OOP/inherit/inherit.cpp)

#oop---inherit_access_authority
add_executable(oop_inherit_acc_auth OOP/inherit/inherit_acc_auth.cpp)

#oop---inherit_destructor_constructor
add_executable(oop_inherit_destructor_constructor OOP/inherit/inherit_destructor_constructor.cpp)

#oop---polymorphism
add_executable(oop_polymorphism OOP/polymorphism/polymorphism.cpp)

############################################
#            generic_program
############################################

#template---function
add_executable(template_func generic_program/template/func_template.cpp)

#template---class
add_executable(template_class generic_program/template/class_template/class_template.cpp)

#template---limit
add_executable(template_limit generic_program/template/template_limit.cpp)

#template---obj_as_param
add_executable(template_obj_as_param generic_program/template/class_template/template_obj_as_param.cpp)

#template---inherit
add_executable(template_inherit generic_program/template/class_template/template_inherit.cpp)

############################################
#                        STL
############################################

#STL----vector
add_executable(stl_vector STL/containers/Sequential_container/vector/vector.cpp)

#STL----nest_vector
add_executable(stl_vector_nest STL/containers/Sequential_container/vector/vector_nest.cpp)

#STL----map
add_executable(stl_map STL/containers/Associative_containers/map/map.cpp)

#STL----map_custom_sort
add_executable(stl_map_custom_sort STL/containers/Associative_containers/map/map_custom_sort.cpp)

#STL----unordered_map
add_executable(stl_unordered_map STL/containers/Associative_containers/map/unordered_map.cpp)


#STL---iterator----iterator
add_executable(stl_iterator STL/iterators/iterator.cpp)


############################################
#              Processes&threads
############################################

#pthread
add_executable(pthread processes_threads/threads/pthread.cpp)

#pthread---detach && join
add_executable(pthread_detach processes_threads/threads/pthread_detach.cpp)

#thread
add_executable(thread processes_threads/threads/thread.cpp)

#synchronization---threads
add_executable(syn_thread processes_threads/synchronization/Threads/Syn_Threads.cpp)

#synchronization---TicketsSale
add_library(tickets_sale processes_threads/synchronization/Threads/TicketsSale.cpp)

add_executable(tickets_sale_test processes_threads/synchronization/Threads/TicketsSale_test.cpp)

target_link_libraries(tickets_sale_test TicketsSale)

############################################
#                 Lambda
############################################

#Lambda
add_executable(lambda Lambda/lambda.cpp)


############################################
#                 memory
############################################

#memory
add_executable(memory memory/memory_partition/memory/memory.cpp)

# memorycoy
add_executable(memcpy memory/memcpy/memcpy.cpp)

#ptr
add_executable(ptr memory/ptr/ptr.cpp)

#smart_ptr---
add_executable(smart_ptr_shared_prt memory/smart_ptr/shared_ptr.cpp)

############################################
#                 draft
############################################

add_executable(test draft/main.cpp)

add_executable(helloworld draft/helloworld.cpp)
